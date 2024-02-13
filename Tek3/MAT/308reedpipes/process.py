#!/usr/bin/env python3

import math
import numpy as np


abscissa = [0, 5, 10, 15, 20]


class Spline:
    def __init__(self, argument):
        """
        Initialise Separation's instance and check little errors
        :param argument: list of float, contains the radius values at each abscissa
        """
        argument = [float(arg) for arg in argument]
        self.variables = {'r0': argument[0], 'r5': argument[1], 'r10': argument[2],
                          'r15': argument[3], 'r20': argument[4], 'n': int(argument[5])}
        self.ordinate = [self.variables[arg] for arg in [
            'r0', 'r5', 'r10', 'r15', 'r20'] if self.variables[arg] != self.variables['n']]
        self.vector = [0] * 5
        self.result = []


def calculate_spline_values(spline):
    """
    Compute the spline values
    """
    first = 6 * (spline.variables['r10'] - 2 *
             spline.variables['r5'] + spline.variables['r0']) / 50
    second = 6 * (spline.variables['r15'] - 2 *
             spline.variables['r10'] + spline.variables['r5']) / 50
    third = 6 * (spline.variables['r20'] - 2 *
             spline.variables['r15'] + spline.variables['r10']) / 50
    spline.vector[2] = (second - (first + third) / 4) * 4 / 7
    spline.vector[1] = first / 2 - 0.25 * spline.vector[2]
    spline.vector[3] = third / 2 - 0.25 * spline.vector[2]
    for i, vec in enumerate(spline.vector):
        if -0.1 < float(spline.vector[i]) < 0.1:
            spline.vector[i] = 0
    for k in range(spline.variables['n']):
        fourth = 20 / (spline.variables['n'] - 1) * k
        i = int((fourth - 0.01) / 5) + 1
        spline_value = (-spline.vector[i - 1] / 30 * pow(fourth - abscissa[i], 3) + spline.vector[i] / 30 * pow(fourth - abscissa[i - 1], 3)
                        - (spline.ordinate[i - 1] / 5 - 5 / 6 *
                           spline.vector[i - 1]) * (fourth - abscissa[i])
                        + (spline.ordinate[i] / 5 - 5 / 6 * spline.vector[i]) * (fourth - abscissa[i - 1]))
        spline.result.append(spline_value)


def print_values(spline):
    """
    Print the computed values
    """
    print(
        f'vector result: [{spline.vector[0]:.1f}, {spline.vector[1]:.1f}, {spline.vector[2]:.1f}, {spline.vector[3]:.1f}, {spline.vector[4]:.1f}]')
    for i in range(spline.variables['n']):
        print(
            f"abscissa: {20 / (spline.variables['n'] - 1) * i:.1f} cm\tradius: {spline.result[i]:.1f} cm")


def process(argv):
    spline = Spline(argv[1:])
    calculate_spline_values(spline)
    print_values(spline)
    return 0
