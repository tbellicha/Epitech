#!/usr/bin/env python3.10
import sys
import os
from Algo import Algo


def process(argc, argv):
    Algo(argv[2], argv[3]).run(argv[1])
    return 0
