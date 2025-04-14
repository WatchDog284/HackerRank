"""
This script prints the multiplication table for a given integer.

Steps:
1. Ensure the script runs as the main program.
2. Read an integer input from the user.
3. Iterate through numbers 1 to 10 using a for loop.
4. For each number, compute the product of the input number and the current number.
5. Display the result in the format: "<input number> x <current number> = <product>".
"""

#!/bin/python3

if __name__ == '__main__':
    n = int(input().strip())
    for i in range(1,11):
        print(f"{n} x {i} = {n * i}")