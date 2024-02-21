#!/usr/bin/env python3

import subprocess

from evaluator_modules import _01_error_management
from evaluator_modules import _02_identity_test

# Constant args
program = ["../push_swap"]
valgrind = ["valgrind", "--leak-check=full", "--show-leak-kinds=all", "--track-origins=yes"]
valgrind_check = "All heap blocks were freed -- no leaks are possible"

# Colours
GREEN = "\033[32;1m"
RED = "\033[31;1m"
COLOR_LIMITER = "\033[0m"
colours = [GREEN, RED, COLOR_LIMITER]

# Make clean and Make
clean = ["make", "clean", "-C", "../"]
subprocess.run(clean, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
make = ["make", "-C", "../"]
subprocess.run(make, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)

# Error management test
print("Error management")
_01_error_management.error_management(program, valgrind, valgrind_check, colours)
print("\n")

# Identity test
print("Identity test")
_02_identity_test.identity_test(program, valgrind, valgrind_check, colours)
print("\n")

subprocess.run(clean, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)