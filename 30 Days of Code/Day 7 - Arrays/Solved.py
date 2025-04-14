#!/bin/python3

import math
import os
import random
import re
import sys

if __name__ == '__main__':
    # Step 1: Read an integer input `n` which represents the size of the array.
    n = int(input().strip())

    # Step 2: Read a line of space-separated integers and convert it into a list `arr`.
    arr = list(map(int, input().rstrip().split()))
    
    # Step 3: Reverse the array `arr` using slicing and join the elements into a space-separated string.
    # Step 4: Print the reversed array as a single line of space-separated integers.
    print(" ".join(map(str, arr[::-1])))
