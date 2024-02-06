#!/usr/bin/env python3

import subprocess

from modules import _01_user_input_validation
from modules import _02_indexing
from modules import _03_moves

program = ["../push_swap"]
valgrind = ["valgrind", "--leak-check=full", "--show-leak-kinds=all", "--track-origins=yes"]
valgrind_check = "All heap blocks were freed -- no leaks are possible"

clean = ["make", "clean", "-C", "../"]
subprocess.run(clean, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)

print("MODULE_1")
make = ["make", "DEBUG=1", "-C", "../"]
subprocess.run(make, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
_01_user_input_validation.user_input(program, valgrind, valgrind_check)
subprocess.run(clean, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
print("\n")

print("MODULE_2")
make = ["make", "DEBUG=2", "-C", "../"]
subprocess.run(make, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
_02_indexing.indexing(program, valgrind, valgrind_check)
subprocess.run(clean, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
print("\n")

print("MODULE_3")
make = ["make", "DEBUG=3", "-C", "../"]
subprocess.run(make, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
_03_moves.moves(program, valgrind, valgrind_check)
subprocess.run(clean, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
print("\n")