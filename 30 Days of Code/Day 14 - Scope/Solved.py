# Define the Difference class to calculate the maximum difference between elements in an array
class Difference:
    def __init__(self, a):
        # Initialize the class with a private list of elements
        self.__elements = a

    # Method to compute the maximum absolute difference between any two elements in the array
    def computeDifference(self):
        # Calculate the maximum difference as the absolute difference between the max and min elements
        self.maximumDifference = abs(max(self.__elements) - min(self.__elements))

# End of Difference class

# Read input (not used directly in the script, but required for HackerRank input format)
_ = input()

# Read the array of integers from input and convert it into a list
a = [int(e) for e in input().split(' ')]

# Create an instance of the Difference class with the input array
d = Difference(a)

# Call the computeDifference method to calculate the maximum difference
d.computeDifference()

# Print the computed maximum difference
print(d.maximumDifference)