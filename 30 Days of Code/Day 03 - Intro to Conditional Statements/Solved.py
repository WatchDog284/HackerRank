"""
This script determines whether a given integer `N` is "Weird" or "Not Weird" based on specific conditions.
Steps:
1. Read an integer input `N` from the user.
2. Check if `N` is odd:
    - If `N` is odd, print "Weird".
3. If `N` is even, evaluate the following conditions:
    - If `N` is in the inclusive range of 2 to 5, print "Not Weird".
    - If `N` is in the inclusive range of 6 to 20, print "Weird".
    - If `N` is greater than 20, print "Not Weird".
4. The output is based on the above conditions and is printed to the console.
"""

#!/bin/python3

import math
import os
import random
import re
import sys

if __name__ == '__main__':
    N = int(input().strip())
    
    if N % 2 != 0:
        print("Weird")
    elif 2 <= N <= 5:
        print("Not Weird")
    elif 6 <= N <= 20:
        print("Weird")
    else:
        print("Not Weird")

# The code above is a solution to the HackerRank problem "Day 3: Intro to Conditional Statements".