#!/usr/bin/python3
# -*- coding: iso-8859-1 -*
""" Python starter bot for the Crypto Trader games, from ex-Riddles.io """
__version__ = "1.0"

from os import F_OK
import sys
import numpy as np

class Bot:
    def __init__(self):
        self.botState = BotState()
        self.algo = Algo()

    def run(self):
        while True:
            try:
                reading = input()
            except EOFError:
                exit(84)
            except KeyboardInterrupt:
                exit(0)
            if len(reading) == 0:
                continue
            self.parse(reading)

    def parse(self, info: str):
        tmp = info.split(" ")
        if tmp[0] == "settings":
            self.botState.update_settings(tmp[1], tmp[2])
            self.algo.period = self.botState.candlesGiven / 3
        if tmp[0] == "update":
            if tmp[1] == "game":
                self.botState.update_game(tmp[2], tmp[3])
                self.algo.periodLastClosePrices = self.botState.charts["USDT_BTC"].closes
                # self.algo.update_lastClosePrices(self.botState)
        if tmp[0] == "action":
            # This won't work every time, but it works sometimes!
            dollars = self.botState.stacks["USDT"]
            btc = self.botState.stacks["BTC"]
            current_closing_price = self.botState.charts["USDT_BTC"].closes[-1]
            affordable = dollars / current_closing_price
            # print(f'${dollars} BTC{btc}', file=sys.stderr)
            # print(f'buy USDT_BTC {0.5 * affordable}', flush=True)
            # print(f'${dollars} BTC{btc}', file=sys.stderr)
            print(f'My stacks are {dollars}. The current closing price is {current_closing_price}. So I can afford {affordable}', file=sys.stderr)
            # if dollars < 100:
            #     print("no_moves", flush=True)
            # else:
            #     print(f'buy USDT_BTC {0.5 * affordable}', flush=True)
            status = self.algo.transaction(dollars, btc)
            if status is False:
                print("no_moves", flush=True)
                print(f'no moves', file=sys.stderr)

class Algo:
    def __init__(self):
        self.period = 0
        self.periodLastClosePrices = []

    def update_lastClosePrices(self, candle) -> None:
        self.periodLastClosePrices.append(candle.charts["USDT_BTC"].closes)
        if self.period != 0:
            # Keep only the `.period` last.
            self.periodLastClosePrices = self.periodLastClosePrices[-self.period:]

    def transaction(self, USDT: float, BTC: float) -> bool:
        lastCloseValue = self.periodLastClosePrices[-1] 
        mean = np.mean(self.periodLastClosePrices)
        std = np.std(self.periodLastClosePrices)
        highBand = mean + (2 * std)
        lowBand = mean - (2 * std)
        money = USDT / lastCloseValue
        buyVal = ((lowBand - lastCloseValue) / 10) * money
        sellVal = ((lastCloseValue - highBand) / 10) * BTC
        print(f'USDT {USDT}, BTC {BTC}, lastCloseVal {lastCloseValue}, money {money}', file=sys.stderr)
        print(f'mean {mean}, std {std}, highBand {highBand}, lowBand {lowBand}, money {money}, lastCloseVal {lastCloseValue} buyVal {buyVal}, sellVal {sellVal}', file=sys.stderr)
        if lastCloseValue < lowBand and money > buyVal and buyVal > 0.0001:
            print(f'buy USDT_BTC {buyVal}', flush=True)
            print(f'buy {buyVal}', file=sys.stderr)
            return True
        elif lastCloseValue > highBand and BTC > sellVal and sellVal > 0.0001:
            print(f'sell USDT_BTC {sellVal}', flush=True)
            print(f'sell {sellVal}', file=sys.stderr)
            return True
        else:
            return False

class Candle:
    def __init__(self, format, intel):
        tmp = intel.split(",")
        for (i, key) in enumerate(format):
            value = tmp[i]
            if key == "pair":
                self.pair = value
            if key == "date":
                self.date = int(value)
            if key == "high":
                self.high = float(value)
            if key == "low":
                self.low = float(value)
            if key == "open":
                self.open = float(value)
            if key == "close":
                self.close = float(value)
            if key == "volume":
                self.volume = float(value)

    def __repr__(self):
        return str(self.pair) + str(self.date) + str(self.close) + str(self.volume)


class Chart:
    def __init__(self):
        self.dates = []
        self.opens = []
        self.highs = []
        self.lows = []
        self.closes = []
        self.volumes = []
        self.indicators = {}

    def add_candle(self, candle: Candle):
        self.dates.append(candle.date)
        self.opens.append(candle.open)
        self.highs.append(candle.high)
        self.lows.append(candle.low)
        self.closes.append(candle.close)
        self.volumes.append(candle.volume)


class BotState:
    def __init__(self):
        self.timeBank = 0
        self.maxTimeBank = 0
        self.timePerMove = 1
        self.candleInterval = 1
        self.candleFormat = []
        self.candlesTotal = 0
        self.candlesGiven = 0
        self.initialStack = 0
        self.transactionFee = 0.2
        self.date = 0
        self.stacks = dict()
        self.charts = dict()

    def update_chart(self, pair: str, new_candle_str: str):
        if not (pair in self.charts):
            self.charts[pair] = Chart()
        new_candle_obj = Candle(self.candleFormat, new_candle_str)
        self.charts[pair].add_candle(new_candle_obj)

    def update_stack(self, key: str, value: float):
        self.stacks[key] = value

    def update_settings(self, key: str, value: str):
        if key == "timebank":
            self.maxTimeBank = int(value)
            self.timeBank = int(value)
        if key == "time_per_move":
            self.timePerMove = int(value)
        if key == "candle_interval":
            self.candleInterval = int(value)
        if key == "candle_format":
            self.candleFormat = value.split(",")
        if key == "candles_total":
            self.candlesTotal = int(value)
        if key == "candles_given":
            self.candlesGiven = int(value)
        if key == "initial_stack":
            self.initialStack = int(value)
        if key == "transaction_fee_percent":
            self.transactionFee = float(value)

    def update_game(self, key: str, value: str):
        if key == "next_candles":
            new_candles = value.split(";")
            self.date = int(new_candles[0].split(",")[1])
            for candle_str in new_candles:
                candle_infos = candle_str.strip().split(",")
                self.update_chart(candle_infos[0], candle_str)
        if key == "stacks":
            new_stacks = value.split(",")
            for stack_str in new_stacks:
                stack_infos = stack_str.strip().split(":")
                self.update_stack(stack_infos[0], float(stack_infos[1]))


if __name__ == "__main__":
    mybot = Bot()
    mybot.run()
