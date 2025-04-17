#!/bin/python3

# Importing necessary libraries
import math  # Provides mathematical functions
import os    # Provides functions for interacting with the operating system
import random  # Provides functions for generating random numbers
import re    # Provides regular expression matching operations
import sys   # Provides access to system-specific parameters and functions

#
# Complete the 'weightedMean' function below.
#
# The function accepts following parameters:
#  1. INTEGER_ARRAY X - List of values
#  2. INTEGER_ARRAY W - List of weights
#

def weightedMean(X, W):
    # Calculate the weighted mean using the formula:
    # weighted_mean = sum(Values * Weights) / sum(Weights)
    # Use list comprehension to multiply corresponding elements of X and W, sum them, 
    # and divide by the sum of weights. Round the result to 1 decimal place.
    wMean = round(sum(x * w for x, w in zip(X, W)) / sum(W), 1)

    # Print the calculated weighted mean
    print(wMean)

if __name__ == '__main__':
    # Read the number of elements in the arrays
    n = int(input().strip())

    # Read the list of values (X) from input and convert them to integers
    vals = list(map(int, input().rstrip().split()))

    # Read the list of weights (W) from input and convert them to integers
    weights = list(map(int, input().rstrip().split()))

    # Call the weightedMean function with the values and weights
    weightedMean(vals, weights)
