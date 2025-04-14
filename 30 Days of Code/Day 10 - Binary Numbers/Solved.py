import math
import os
import random
import re
import sys

#!/bin/python3


if __name__ == '__main__':
    n = int(input().strip())
    
    # Convert the number to binary and split by '0' to find consecutive '1's
    binary_representation = bin(n)[2:]
    consecutive_ones = binary_representation.split('0')
    
    # Find the maximum length of consecutive '1's
    max_consecutive_ones = max(len(ones) for ones in consecutive_ones)
    
    print(max_consecutive_ones)