# Define a base class `Person` to represent a generic person
class Person:
    # Constructor to initialize the first name, last name, and ID number of the person
    def __init__(self, firstName, lastName, idNumber):
        self.firstName = firstName
        self.lastName = lastName
        self.idNumber = idNumber

    # Method to print the person's details in a formatted way
    def printPerson(self):
        print("Name:", self.lastName + ",", self.firstName)
        print("ID:", self.idNumber)


# Define a derived class `Student` that inherits from `Person`
class Student(Person):
    # Constructor to initialize the student details, including scores
    def __init__(self, firstName, lastName, idNumber, scores):
        # Call the parent class constructor to initialize common attributes
        super().__init__(firstName, lastName, idNumber)
        self.scores = scores

    # Method to calculate the grade based on the average score
    def calculate(self):
        avg = sum(self.scores) / len(self.scores)  # Calculate the average score
        # Determine the grade based on the average score
        if avg >= 90:
            return 'O'  # Outstanding
        elif avg >= 80:
            return 'E'  # Exceeds Expectations
        elif avg >= 70:
            return 'A'  # Acceptable
        elif avg >= 55:
            return 'P'  # Poor
        elif avg >= 40:
            return 'D'  # Dreadful
        else:
            return 'T'  # Troll


# Read input for the student's first name, last name, and ID number
line = input().split()
firstName = line[0]
lastName = line[1]
idNum = line[2]

# Read the number of scores (not used in Python but part of the input format)
numScores = int(input())

# Read the scores as a list of integers
scores = list(map(int, input().split()))

# Create a `Student` object with the provided details
s = Student(firstName, lastName, idNum, scores)

# Print the student's personal details
s.printPerson()

# Print the student's grade based on the calculated average score
print("Grade:", s.calculate())
