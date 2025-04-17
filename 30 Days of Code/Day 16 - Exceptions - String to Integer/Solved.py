#!/bin/python3

# Import the sys module (not used in this script but commonly included for handling system-specific parameters and functions)
import sys

# Read input from the user as a string
S = input()

# Try to convert the input string to an integer
try:
    # If successful, print the integer value
    print(int(S))
# Handle the case where the input cannot be converted to an integer
except ValueError:
    # Print "Bad String" if a ValueError occurs
    print("Bad String")