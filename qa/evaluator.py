#!/usr/bin/env python3

import subprocess

from evaluator_modules import _01_error_management
from evaluator_modules import _02_identity_test
from evaluator_modules import _03_simple_version
from evaluator_modules import _04_another_simple_version
from evaluator_modules import _05_middle_version
from evaluator_modules import _06_advanced_version
from evaluator_modules import _07_nothing_on_list_2
from evaluator_modules import _08_space_on_list

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

# Simple version
print("Simple version")
_03_simple_version.simple_version(program, valgrind, valgrind_check, colours)
print("\n")

# Another simple version
print("Another simple version")
_04_another_simple_version.another_simple_version(program, valgrind, valgrind_check, colours)
print("\n")

# Middle version
print("Middle version")
_05_middle_version.middle_version(program, valgrind, valgrind_check, colours)
print("\n")

# Advanced version
print("Advanced version")
_06_advanced_version.advanced_version(program, valgrind, valgrind_check, colours)
print("\n")

# Nothing on list "''"
print("Nothing on list 2 "''"")
_07_nothing_on_list_2.nothing_on_list_2(program, valgrind, valgrind_check, colours)
print("\n")

# Space on list "' '"
print("Sapce on list "' '"")
_08_space_on_list.space_on_list(program, valgrind, valgrind_check, colours)
print("\n")

subprocess.run(clean, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)