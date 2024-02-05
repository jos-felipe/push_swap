#!/usr/bin/env python3

import subprocess

from modules import _01_user_input_validation
from modules import _02_indexing
from modules import _03_moves

clean = ["make", "clean", "-C", "../"]
subprocess.run(clean, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)

print("MODULE_1")
make = ["make", "DEBUG=1", "-C", "../"]
subprocess.run(make, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
_01_user_input_validation.user_input()
subprocess.run(clean, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
print("\n")

print("MODULE_2")
make = ["make", "DEBUG=2", "-C", "../"]
subprocess.run(make, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
_02_indexing.indexing()
subprocess.run(clean, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
print("\n")

print("MODULE_3")
make = ["make", "DEBUG=3", "-C", "../"]
subprocess.run(make, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
_03_moves.moves()
subprocess.run(clean, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
print("\n")