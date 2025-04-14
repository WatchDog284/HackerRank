"""
Calculate and print the total cost of a meal, including tip and tax.

Args:
    meal_cost (float): The base cost of the meal.
    tip_percent (int): The percentage of the meal cost to be added as a tip.
    tax_percent (int): The percentage of the meal cost to be added as tax.

Steps:
    1. Calculate the tip amount by multiplying the meal cost by the tip percentage divided by 100.
    2. Calculate the tax amount by multiplying the meal cost by the tax percentage divided by 100.
    3. Compute the total cost by summing the meal cost, tip amount, and tax amount.
    4. Round the total cost to the nearest integer.
    5. Print the rounded total cost.
"""

#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'solve' function below.
#
# The function accepts following parameters:
#  1. DOUBLE meal_cost
#  2. INTEGER tip_percent
#  3. INTEGER tax_percent
#

def solve(meal_cost, tip_percent, tax_percent):
    # Write your code here
    tip = meal_cost/100 * tip_percent
    tax = tax_percent/100 * meal_cost
    total_cost = round(meal_cost + tip + tax)
    print(total_cost)

if __name__ == '__main__':
    meal_cost = float(input().strip())

    tip_percent = int(input().strip())

    tax_percent = int(input().strip())

    solve(meal_cost, tip_percent, tax_percent)
