#!/usr/bin/env python3

import subprocess

from modules import _01_user_input_validation
from modules import _02_indexing
from modules import _03_moves
from modules import _04_pre_sort
from modules import _04_tiny_sort
from modules import _05_target_position
from modules import _06_comp_cost

# Constant args
program = ["../push_swap"]
valgrind = ["valgrind", "--leak-check=full", "--show-leak-kinds=all", "--track-origins=yes"]
valgrind_check = "All heap blocks were freed -- no leaks are possible"

# Colours
GREEN = "\033[32;1m"
RED = "\033[31;1m"
COLOR_LIMITER = "\033[0m"
colours = [GREEN, RED, COLOR_LIMITER]

clean = ["make", "clean", "-C", "../"]
subprocess.run(clean, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)

print("MODULE_1")
make = ["make", "DEBUG=1", "-C", "../"]
subprocess.run(make, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
_01_user_input_validation.user_input(program, valgrind, valgrind_check, colours)
subprocess.run(clean, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
print("\n")

print("MODULE_2")
make = ["make", "DEBUG=2", "-C", "../"]
subprocess.run(make, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
_02_indexing.indexing(program, valgrind, valgrind_check, colours)
subprocess.run(clean, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
print("\n")

print("MODULE_3")
make = ["make", "DEBUG=3", "-C", "../"]
subprocess.run(make, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
_03_moves.moves(program, valgrind, valgrind_check, colours)
subprocess.run(clean, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
print("\n")

print("MODULE_4")
make = ["make", "DEBUG=4", "-C", "../"]
subprocess.run(make, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
_04_pre_sort.pre_sort(program, valgrind, valgrind_check, colours)
subprocess.run(clean, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
subprocess.run(make, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
print("Tiny sort")
_04_tiny_sort.tiny_sort(program, valgrind, valgrind_check, colours)
subprocess.run(clean, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
print("\n")

print("MODULE_5")
make = ["make", "DEBUG=5", "-C", "../"]
subprocess.run(make, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
_05_target_position.target_position(program, valgrind, valgrind_check, colours)
subprocess.run(clean, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
print("\n")

print("MODULE_6")
make = ["make", "DEBUG=6", "-C", "../"]
subprocess.run(make, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
_06_comp_cost.comp_cost(program, valgrind, valgrind_check, colours)
subprocess.run(clean, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
print("\n")