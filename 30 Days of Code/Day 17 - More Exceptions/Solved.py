class Calculator:
    # Define a method `power` that calculates n raised to the power of p
    def power(self, n, p):
        # Check if either n or p is negative
        if n < 0 or p < 0:
            # Raise a ValueError if n or p is negative
            raise ValueError("n and p should be non-negative")
        # Return the result of n raised to the power of p
        return n ** p

# Create an instance of the Calculator class
myCalculator = Calculator()

# Read the number of test cases
T = int(input())

# Loop through each test case
for _ in range(T):
    # Read two integers n and p from input
    n, p = map(int, input().split())
    try:
        # Try to calculate n raised to the power of p
        ans = myCalculator.power(n, p)
        # Print the result
        print(ans)
    except Exception as e:
        # Print the exception message if an error occurs
        print(e)