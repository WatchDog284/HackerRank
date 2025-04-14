"""
This script demonstrates the use of a class to model a person's age and behavior based on their age.

Define the Person class:
- The __init__ method initializes the person's age and checks if the initial age is valid.
- The amIOld method determines the age category of the person and prints a corresponding message.
- The yearPasses method increments the person's age by one year.

Read the number of test cases:
- Input: number of test cases.

For each test case:
- Input the initial age of the person.
- Create a new Person object with the given age.
- Print the age category of the person.
- Simulate the passage of 3 years and print the new age category after 3 years.
- Print a blank line for separation between test cases.
"""

class Person:
    def __init__(self,initialAge):
        # Add some more code to run some checks on initialAge
        if initialAge < 0:
            self.age = 0
            print("Age is not valid, setting age to 0.")
        else:
            self.age = initialAge
    def amIOld(self):
        # Do some computations in here and print out the correct statement to the console
        if self.age < 13:
            print("You are young.")
        elif 13 <= self.age < 18:
            print("You are a teenager.")
        else:
            print("You are old.")
    def yearPasses(self):
        # Increment the age of the person in here
        self.age = self.age + 1

t = int(input())
for i in range(0, t):
    age = int(input())         
    p = Person(age)  
    p.amIOld()
    for j in range(0, 3):
        p.yearPasses()       
    p.amIOld()
    print("")