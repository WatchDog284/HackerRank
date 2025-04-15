# Define a Node class to represent each element in the linked list
class Node:
    def __init__(self, data):
        self.data = data  # Store the data value of the node
        self.next = None  # Initialize the next pointer to None

# Define a Solution class to handle linked list operations
class Solution: 
    # Method to display the elements of the linked list
    def display(self, head):
        current = head  # Start from the head of the linked list
        while current:  # Traverse the list until the end
            print(current.data, end=' ')  # Print the data of the current node
            current = current.next  # Move to the next node

    # Method to insert a new node at the end of the linked list
    def insert(self, head, data): 
        # Create a new node with the given data
        new_node = Node(data)
        # If the linked list is empty, return the new node as the head
        if head is None:
            return new_node
        else:
            # Traverse the list to find the last node
            current = head
            while current.next:
                current = current.next
            # Link the last node to the new node
            current.next = new_node
        # Return the head of the updated linked list
        return head
        
    # Method to display the elements of the linked list (duplicate definition, can be removed)
    def display(self, head):
        current = head  # Start from the head of the linked list
        while current:  # Traverse the list until the end
            print(current.data, end=' ')  # Print the data of the current node
            current = current.next  # Move to the next node

# Create an instance of the Solution class
mylist = Solution()

# Read the number of elements to be inserted into the linked list
T = int(input())

# Initialize the head of the linked list to None
head = None

# Loop to read data and insert nodes into the linked list
for i in range(T):
    data = int(input())  # Read the data for the new node
    head = mylist.insert(head, data)  # Insert the new node into the linked list

# Display the elements of the linked list
mylist.display(head)