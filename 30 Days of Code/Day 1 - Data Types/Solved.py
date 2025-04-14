"""
This script demonstrates basic operations with integers, floating-point numbers, and strings.
It performs the following steps:

1. Declare and initialize three variables:
    - An integer `i` with a value of 4.
    - A floating-point number `d` with a value of 4.0.
    - A string `s` with a value of 'HackerRank '.

2. Read user input for:
    - An integer, which is stored in `myInt`.
    - A floating-point number, which is stored in `myDouble`.
    - A string, which is stored in `myString`.

3. Perform the following operations:
    - Add the integer `i` to `myInt` and print the result.
    - Add the floating-point number `d` to `myDouble` and print the result.
    - Concatenate the string `s` with `myString` and print the result.
"""

i = 4
d = 4.0
s = 'HackerRank '

# Declare second integer, double, and String variables.
# Read and save an integer, double, and String to your variables.
myInt = int(input())
myDouble = float(input())
myString = input()

# Print the sum of both integer variables on a new line.
print(i + myInt)

# Print the sum of the double variables on a new line.
print(d + myDouble)

# Concatenate and print the String variables on a new line
# The 's' variable above should be printed first.
print(s + myString)
