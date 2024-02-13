#!/usr/bin/env python3
import subprocess
from typing import List


def test_pdf_1():
    expected_result: bytes = \
        b'   x\t| 0-1\t| 2\t| 3\t| 4\t| 5\t| 6\t| 7+\t| Total\n' \
        b'  Ox\t| 10\t| 10\t| 18\t| 20\t| 19\t| 11\t| 12\t| 100\n' \
        b'  Tx\t| 8.0\t| 13.8\t| 19.2\t| 19.9\t| 16.3\t| 11.1\t| 11.7\t| 100\n' \
        b'Distribution:\t\tB(100, 0.0410)\n' \
        b'Chi-squared:\t\t2.029\n' \
        b'Degrees of freedom:\t5\n' \
        b'Fit validity:\t\t80% < P < 90%\n'
    check_program(b'', expected_result, ["./208dowels", "6", "4", "10", "18", "20", "19", "11", "5", "7"])


def test_pdf_2():
    expected_result: bytes = \
        b'   x\t| 0-1\t| 2-3\t| 4\t| 5\t| 6-7\t| 8+\t| Total\n' \
        b'  Ox\t| 10\t| 18\t| 20\t| 19\t| 16\t| 17\t| 100\n' \
        b'  Tx\t| 5.2\t| 26.7\t| 19.1\t| 17.7\t| 22.2\t| 9.0\t| 100\n' \
        b'Distribution:\t\tB(100, 0.0460)\n' \
        b'Chi-squared:\t\t16.119\n' \
        b'Degrees of freedom:\t4\n' \
        b'Fit validity:\t\tP < 1%\n'
    check_program(b'', expected_result, ["./208dowels", "6", "4", "10", "8", "20", "19", "11", "5", "17"])


def test_pdf_3():
    expected_result: bytes = \
        b'   x\t| 0-2\t| 3\t| 4\t| 5\t| 6\t| 7+\t| Total\n' \
        b'  Ox\t| 22\t| 19\t| 20\t| 16\t| 12\t| 11\t| 100\n' \
        b'  Tx\t| 23.1\t| 19.7\t| 19.9\t| 16.0\t| 10.6\t| 10.7\t| 100\n' \
        b'Distribution:\t\tB(100, 0.0401)\n' \
        b'Chi-squared:\t\t0.270\n' \
        b'Degrees of freedom:\t4\n' \
        b'Fit validity:\t\tP > 99%\n'
    check_program(b'', expected_result, ["./208dowels", "4", "5", "13", "19", "20", "16", "12", "7", "4"])


def check_program(stdin: bytes, expected_stdout: bytes, params: List[str]):
    res = subprocess.run([params[0], params[1], params[2], params[3], params[4], params[5], params[6], params[7], params[8], params[9]], input=stdin, capture_output=True)
    assert res.stdout == expected_stdout, res.stdout
