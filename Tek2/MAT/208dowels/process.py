#!/usr/bin/env python3

import math
import main
import sys

values = [[0.00, 0.02, 0.06, 0.15, 0.27, 0.45, 0.71, 1.07, 1.64, 2.71, 3.84, 5.41, 6.63],
          [0.02, 0.21, 0.45, 0.71, 1.02, 1.39, 1.83, 2.41, 3.22, 4.61, 5.99, 7.82, 9.21],
          [0.11, 0.58, 1.01, 1.42, 1.87, 2.37, 2.95, 3.66, 4.64, 6.25, 7.81, 9.84, 11.35],
          [0.30, 1.06, 1.65, 2.19, 2.75, 3.36, 4.04, 4.88, 5.99, 7.78, 9.49, 11.67, 13.28],
          [0.55, 1.61, 2.34, 3.00, 3.66, 4.35, 5.13, 6.06, 7.29, 9.24, 11.07, 13.33, 15.01],
          [0.70, 2.20, 3.07, 3.83, 4.57, 5.35, 6.21, 7.23, 8.56, 10.64, 12.59, 15.03, 16.81],
          [1.24, 2.83, 3.82, 4.67, 5.49, 6.35, 7.28, 8.38, 9.80, 12.02, 14.07, 16.62, 18.48],
          [1.65, 3.49, 4.59, 5.53, 6.42, 7.34, 8.35, 9.52, 11.03, 13.36, 15.51, 18.17, 20.09],
          [2.09, 4.17, 5.38, 6.39, 7.36, 8.34, 9.41, 10.66, 12.24, 14.68, 16.92, 19.63, 21.67],
          [2.56, 4.87, 6.18, 7.27, 8.30, 9.34, 10.47, 11.78, 13.44, 15.99, 18.31, 21.16, 23.21]]

percentage = ['P > 99%', '90% < P < 99%', '80% < P < 90%', '70% < P < 80%', '60% < P < 70%', '50% < P < 60%',
              '40% < P < 50%',
              '30% < P < 40%', '20% < P < 30%',
              '10% < P < 20%', '5% < P < 10%', '2% < P < 5%', '1% < P < 2%', 'P < 1%']


def binomial_coef(n, k):
    return math.factorial(n) / (math.factorial(k) * math.factorial(n - k))


def get_binomial(n, k, p):
    return binomial_coef(n, k) * math.pow(p, k) * math.pow(1 - p, n - k)


def get_period(tab):
    return sum([i * s for i, s in enumerate(tab)]) / 10000


def get_sd(Ox, tx):
    line = [[i] for i in range(9)]
    i = 0
    while i < len(line):
        if sum([Ox[j] for j in line[i]]) >= 10:
            i += 1
            continue
        if (i + 1 == len(line)) or (i > 0 and sum([Ox[j] for j in line[i - 1]]) < sum(Ox[j] for j in line[i + 1])):
            line[i - 1] += line[i]
            del line[i]
            i -= 1
        else:
            line[i] += line[i + 1]
            del line[i + 1]
    chi = sum([math.pow(sum([Ox[i] - tx[i] for i in cell]), 2) / sum([tx[i] for i in cell]) for cell in line])
    return line, chi


def process():
    Ox = main.parse_args()
    period = get_period(Ox)
    tx = [100 * get_binomial(100, i, period) for i in range(8)]
    tx.append(100 - sum(tx))
    line, chi = get_sd(Ox, tx)
    deg = len(line) - 2
    if deg < 1:
        sys.exit(84)
    tab = [['   x'], ['  Ox'], ['  Tx']]
    for cell in line:
        column = ['%d' % cell[0], '%d' % sum([Ox[i] for i in cell]), '%.1f' % sum([tx[i] for i in cell])]
        if len(cell) > 1 or cell[0] == 8:
            column[0] += ('-%d' % cell[-1]) if cell[-1] != 8 else '+'
        for i, row in enumerate(column):
            tab[i].append(row)
    for i, row in enumerate(['Total', '100', '100']):
        tab[i].append(row)
    for row in tab:
        print("\t| ".join("%s" % k for k in row))
    f = -1
    for i, l in enumerate(values[deg - 1]):
        if chi < l:
            f = i
            break
    print('Distribution:\t\tB(100, %.4f)' % period)
    print('Chi-squared:\t\t%.3f' % chi)
    print('Degrees of freedom:\t%d' % deg)
    print('Fit validity:\t\t%s' % percentage[f])
    return 0
