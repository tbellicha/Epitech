#!/usr/bin/env python3.10
import results


def process(argc, argv):
    mean = int(argv[1])
    std_dev = int(argv[2])
    if argc == 3:
        results.basic(mean, std_dev)
    elif argc == 4:
        qi1 = int(argv[3])
        results.inferior(mean, std_dev, qi1)
    elif argc == 5:
        qi1 = int(argv[3])
        qi2 = int(argv[4])
        results.superior(mean, std_dev, qi1, qi2)
    return 0
