#!/usr/bin/env python3

import sys
import random
import math
from typing import List, OrderedDict
import numpy as np


def calcul_sigma(values: List[float], nb_days: int) -> float:
    mean: float = 0.00
    l_values: int = len(values)
    for i in range(l_values - nb_days, l_values):
        mean += values[i]
    mean: float = mean / nb_days
    mean_deviation: List[float] = []
    for i in range(l_values - nb_days, l_values):
        mean_deviation.append(pow(values[i] - mean, 2))
    sum_square: float = sum(mean_deviation)
    variances: float = sum_square / nb_days
    return math.sqrt(variances)


def calcul_g(values: List[float], nb_days: int) -> float:
    l_values: int = len(values)
    g = 0.0
    for i in range(l_values - nb_days, l_values):
        n = values[i] - values[i - 1]
        if n > 0:
            g += n
    g /= nb_days
    if g < 0.00:
        g = 0.00
    return g


def get_weirdest_values(values_entered: List[float], nb_days: int, f_inpout: float, weirdest_values: List[float]):
    period_array: list = list()
    last_period: int = len(values_entered) - nb_days
    for i in range(last_period, len(values_entered)):
        period_array.append(values_entered[i])
    period_array.sort()
    q1: float = np.quantile(period_array, 0.25)
    q3: float = np.quantile(period_array, 0.75)
    interquartile_range: float = q3 - q1
    interval_limit: float = 0.8 * interquartile_range
    interval_limit_inf: float = q1 - interval_limit
    interval_limit_sup: float = q3 + interval_limit
    if f_inpout < interval_limit_inf or f_inpout > interval_limit_sup:
        weirdest_values.append(f_inpout)
    return weirdest_values


def get_top_weirdest_values(values_entered: List[float], weirdest_values: List[float]):
    try:
        average: float = sum(weirdest_values) / len(weirdest_values)
    except ZeroDivisionError:
        average: float = 0
    diction: dict = dict()
    for i in weirdest_values:
        nb: float = average - i
        nb = nb ** 2
        diction[round(nb, 2)] = i
    diction = dict(OrderedDict(sorted(diction.items(), key=lambda t: t[0], reverse=True)))
    final_list: list = list(diction.values())
    if len(final_list) > 5:
        while len(final_list) > 5:
            final_list.pop()
    elif len(final_list) < 5:
        while len(final_list) < 5:
            to_add: float = random.choice(values_entered)
            if final_list.count(to_add) <= (values_entered.count(to_add) - 1):
                final_list.append(to_add)
            if 5 > len(values_entered) == len(final_list):
                break
    return final_list


def print_helper() -> None:
    print("SYNOPSIS")
    print("\t./groundhog period")
    print("\nDESCRIPTION")
    print("\tperiod\tthe number of days defining a period")
    sys.exit(0)


def print_resume(nb_switched: int, values_entered: List[float], weirdest_values: List[float], has_done_period: bool) -> None:
    five_weirdest = list()
    if has_done_period:
        print("Global tendency switched %d times" % nb_switched)
        five_weirdest = get_top_weirdest_values(values_entered, weirdest_values)
        print(len(five_weirdest), "weirdest values are", five_weirdest)
        sys.exit(0)
    sys.exit(84)


def print_line(g: float, r: float, s: float, switch: bool, passed_days: int, period: int) -> None:
    if passed_days <= period:
        g_str: str = "nan"
        r_str: str = "nan"
        if passed_days == period:
            s_str: str = '{:.2f}'.format(s)
        else:
            s_str: str = "nan"
    else:
        g_str: str = '{:.2f}'.format(g)
        r_str: str = str(int(round(r)))
        s_str: str = '{:.2f}'.format(s)
    if switch:
        print("g=" + g_str + "\t\tr=" + r_str + "%\t\ts=" + s_str + "\t\ta switch occurs")
    else:
        print("g=" + g_str + "\t\tr=" + r_str + "%\t\ts=" + s_str)


def read_input(nb_switched: int, values_entered: List[float], weirdest_values: List[float], has_done_period: bool) -> float:
    try:
        inpout: str = str(input())
    except KeyboardInterrupt:
        sys.exit(84)
    except EOFError:
        sys.exit(84)
    if inpout == "STOP":
        print_resume(nb_switched, values_entered, weirdest_values, has_done_period)
    try:
        f_inpout: float = float(inpout)
    except ValueError:
        sys.exit(84)
    return f_inpout


def check_args(argv: List[str]):
    if len(argv) != 2 or not argv[1].isnumeric() or int(argv[1]) <= 0:
        if len(argv) == 2:
            if argv[1] == "-h":
                print_helper()
            elif argv[1] == "-t":
                sys.exit(0)
            else:
                sys.exit(84)
        else:
            sys.exit(84)


def main() -> None:
    check_args(sys.argv)
    values_entered: List[float] = []
    weirdest_values: List[float] = []
    g: float = 0.00
    r: float = 0.00
    s: float = 0.00
    f_inpout: float = 0.00
    nb_days: int = int(sys.argv[1])
    l_values: int = 0
    nb_switched: int = 0
    num_day: int = 0
    new_r: float = 0.00
    is_enough_period: bool = False
    while 1:
        is_enough_period = nb_days <= num_day
        f_inpout = read_input(nb_switched, values_entered, weirdest_values, is_enough_period)
        values_entered.append(f_inpout)
        l_values = len(values_entered)
        has_switched: bool = False
        if l_values > nb_days:
            g = calcul_g(values_entered, nb_days)
            if abs(values_entered[l_values - nb_days - 1]) == 0:
                new_r = 1000.0
            else:
                new_r = (f_inpout - values_entered[l_values - nb_days - 1]) / abs(values_entered[l_values - nb_days - 1]) * 100
            if (new_r > 0 and r < 0) or (new_r < 0 and r > 0):
                has_switched = True
                nb_switched += 1
            r = new_r
        if l_values >= nb_days:
            s = calcul_sigma(values_entered, nb_days)
        num_day += 1
        if len(values_entered) >= nb_days:
            weirdest_values = get_weirdest_values(values_entered, nb_days, f_inpout, weirdest_values)
        print_line(g, r, s, has_switched, num_day, nb_days)


if __name__ == '__main__':
    main()
