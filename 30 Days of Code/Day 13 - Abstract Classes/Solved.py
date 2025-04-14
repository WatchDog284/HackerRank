from abc import ABCMeta, abstractmethod

# Define an abstract base class 'Book' using ABCMeta as the metaclass
class Book(object, metaclass=ABCMeta):
    # Constructor to initialize title and author attributes
    def __init__(self, title, author):
        self.title = title
        self.author = author
    
    # Abstract method 'display' to be implemented by subclasses
    @abstractmethod
    def display(self):
        pass

# Define a concrete subclass 'MyBook' that inherits from 'Book'
class MyBook(Book):
    # Constructor to initialize title, author, and price attributes
    def __init__(self, title, author, price):
        # Call the parent class constructor to initialize title and author
        super().__init__(title, author)
        self.price = price
    
    # Implement the abstract method 'display' to print book details
    def display(self):
        print(f"Title: {self.title}")  # Print the title of the book
        print(f"Author: {self.author}")  # Print the author of the book
        print(f"Price: {self.price}")  # Print the price of the book

# Read input for the title of the book
title = input()
# Read input for the author of the book
author = input()
# Read input for the price of the book and convert it to an integer
price = int(input())

# Create an instance of 'MyBook' with the provided title, author, and price
new_novel = MyBook(title, author, price)
# Call the 'display' method to print the book details
new_novel.display()