#!/usr/bin/env python3
import subprocess


def test_pdf():
    expected_result: bytes = b'g=nan\t\tr=nan%\t\ts=nan\n'
    check_program(b'0.00', expected_result)


def check_program(stdin: bytes, expected_stdout: bytes):
    res = subprocess.run(["./groundhog", "7"], input=stdin, capture_output=True)
    assert res.stdout == expected_stdout
