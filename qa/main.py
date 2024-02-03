#!/usr/bin/env python3

import subprocess

from modules import _01_user_input_validation
from modules import _02_indexing

fclean = ["make", "fclean", "-C", "../"]
subprocess.run(fclean, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)

print("MODULE_1")
make = ["make", "DEBUG=1", "-C", "../"]
subprocess.run(make, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
_01_user_input_validation.user_input()
subprocess.run(fclean, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
print("\n")

print("MODULE_2")
make = ["make", "DEBUG=2", "-C", "../"]
subprocess.run(make, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
_02_indexing.indexing()
subprocess.run(fclean, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
print("\n")