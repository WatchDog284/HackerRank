import numpy as np  # Importing the NumPy library for numerical computations
from scipy import stats  # Importing the stats module from SciPy for statistical calculations

n = int(input())  # Reading the size of the list from user input
arr = list(map(int, input().split()))  # Reading a space-separated list of integers and converting it to a Python list

print(np.mean(arr))  # Calculating and printing the mean (average value) of the list
print(np.median(arr))  # Calculating and printing the median (middle value) of the list
print(int(stats.mode(arr)[0]))  # Calculating and printing the mode (most frequent value) of the list