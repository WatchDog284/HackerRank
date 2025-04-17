import statistics  # Importing the statistics module (not used in this script)
from collections import Counter  # Importing Counter to calculate the mode

# Read the number of elements in the array
n = int(input())

# Read the array elements, split them into integers, and store them in a list
arr = list(map(int, input().split()))

# Sort the array in ascending order
arr.sort()

# Calculate the mean (average) of the array
mean = sum(arr) / n

# Calculate the median
# If the number of elements is odd, take the middle element
# If even, take the average of the two middle elements
median = arr[n // 2] if n % 2 != 0 else (arr[n // 2 - 1] + arr[n // 2]) / 2

# Calculate the mode (most frequent element) using Counter
mode = Counter(arr).most_common(1)[0][0]

# Print the mean rounded to 1 decimal place
print(f"{mean:.1f}")

# Print the median rounded to 1 decimal place
print(f"{median:.1f}")

# Print the mode
print(mode)