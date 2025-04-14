import math
import os
import random
import re
import sys

#!/bin/python3


# Function to calculate the maximum hourglass sum in a 6x6 2D array
def hourglassSum(arr):
    max_sum = -63  # Minimum possible value for an hourglass (-9 * 7)
    for i in range(4):  # Loop through rows
        for j in range(4):  # Loop through columns
            # Calculate the sum of the current hourglass
            top = arr[i][j] + arr[i][j+1] + arr[i][j+2]
            middle = arr[i+1][j+1]
            bottom = arr[i+2][j] + arr[i+2][j+1] + arr[i+2][j+2]
            hourglass = top + middle + bottom
            # Update max_sum if the current hourglass sum is greater
            max_sum = max(max_sum, hourglass)
    return max_sum

if __name__ == '__main__':
    arr = []
    for _ in range(6):
        arr.append(list(map(int, input().rstrip().split())))
    # Output the maximum hourglass sum
    print(hourglassSum(arr))