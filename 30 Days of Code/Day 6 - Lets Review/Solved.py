"""
This script processes multiple strings to separate their characters into even-indexed and odd-indexed groups.
    
Steps:
    1. Define a function `processString(s)` that:
        - Extracts characters at even indices from the input string `s`.
        - Extracts characters at odd indices from the input string `s`.
        - Prints the even-indexed characters and odd-indexed characters separated by a space.
    2. Read an integer `t` from the input, representing the number of test cases.
    3. For each test case:
        - Read a string `s` from the input.
        - Call the `processString(s)` function to process and display the result.
"""

def processString(s):
    even_chars = s[::2]
    odd_chars = s[1::2]
    
    print(f"{even_chars} {odd_chars}")
    
t = int(input())

for _ in range(t):
    s = input().strip()
    processString(s)