#!/usr/bin/python3
# -*- coding: iso-8859-1 -*
""" Python starter bot for the Crypto Trader games, from ex-Riddles.io """
__version__ = "1.0"

import sys
import math
from typing import List

values_entered: List[float] = []
r_values: List[float] = []
period_days: int = 2
days_passed: int = 0
stop: bool = False


class Bot:
    def __init__(self):
        self.botState = BotState()

    def run(self):
        while True:
            reading = input()
            if len(reading) == 0:
                continue
            self.parse(reading)

    def parse(self, info: str) -> None:
        tmp = info.split(" ")
        if tmp[0] == "settings":
            self.botState.update_settings(tmp[1], tmp[2])
        if tmp[0] == "update":
            if tmp[1] == "game":
                self.botState.update_game(tmp[2], tmp[3])
        if tmp[0] == "action":
            global stop
            dollars = self.botState.stacks["USDT"]
            btc_stack = self.botState.stacks["BTC"]
            current_opening_price = self.botState.charts["USDT_BTC"].opens[-1]
            current_closing_price = self.botState.charts["USDT_BTC"].closes[-1]
            values_entered.append(current_opening_price)
            l_values: int = len(values_entered)
            affordable = dollars / current_opening_price
            global days_passed
            value = dollars + btc_stack * current_closing_price
            if value >= 1150 and not stop:
                stop = True
                print(f'sell USDT_BTC {btc_stack}', flush=True)
                days_passed += 1
                return
            if value <= 850 and not stop:
                stop = True
                print(f'sell USDT_BTC {btc_stack}', flush=True)
                days_passed += 1
                return
            to_buy = 0.9 * affordable
            to_sell = 0.06 * btc_stack
            if days_passed > period_days and not stop:
                r_values.append((current_closing_price - values_entered[l_values - period_days - 1]) /
                                abs(values_entered[l_values - period_days - 1]) * 100)
                print(f'R = {r_values[-1]}.', file=sys.stderr)
                if len(r_values) > 1:
                    if r_values[-1] < 0 and r_values[-2] > 0 and 0.00001 < to_sell:
                        print(f'sell USDT_BTC {to_sell}', flush=True)
                    elif r_values[-1] > 0 and r_values[-2] < 0:
                        print(f'buy USDT_BTC {to_buy}', flush=True)
                    else:
                        print(f'no_moves')
                else:
                    print(f'no_moves')
            else:
                print(f'no_moves')
            days_passed += 1


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
        self.transactionFee = 0.0
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
                print(f'{stack_infos[0]} = {float(stack_infos[1])}', file=sys.stderr)
            print(f'', file=sys.stderr)


if __name__ == "__main__":
    mybot = Bot()
    mybot.run()
