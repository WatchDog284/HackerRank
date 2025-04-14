class Person:
    # Constructor for the Person class to initialize first name, last name, and ID number
    def __init__(self, firstName, lastName, idNumber):
        self.firstName = firstName
        self.lastName = lastName
        self.idNumber = idNumber

    # Method to print the person's details
    def printPerson(self):
        print("Name:", self.lastName + ",", self.firstName)
        print("ID:", self.idNumber)

class Student(Person):
    # Constructor for the Student class, inheriting from Person
    # Initializes first name, last name, ID number, and test scores
    def __init__(self, firstName, lastName, idNumber, scores):
        super().__init__(firstName, lastName, idNumber)  # Call the parent class constructor
        self.scores = scores  # Store the test scores

    # Method to calculate the grade based on the average of test scores
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

# Read the number of scores (not used in Python) and the scores themselves
numScores = int(input())  # Number of scores (not needed for processing in Python)
scores = list(map(int, input().split()))  # Convert input scores to a list of integers

# Create a Student object with the provided details
s = Student(firstName, lastName, idNum, scores)

# Print the student's personal details
s.printPerson()

# Print the student's grade based on the calculated average
print("Grade:", s.calculate())