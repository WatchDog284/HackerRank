#include <stdlib.h>
#include <stdio.h>	

// Define a structure for a Node in the linked list
typedef struct Node
{
    int data;              // Data stored in the node
    struct Node* next;     // Pointer to the next node in the list
}Node;

// Function to insert a new node at the end of the linked list
Node* insert(Node *head, int data)
{
    // Allocate memory for a new node and initialize its data and next pointer
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    
    // If the list is empty, the new node becomes the head
    if(head == NULL){
        return newNode;
    } else {
        // Traverse the list to find the last node
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        // Link the new node to the end of the list
        temp->next = newNode;
    }
    // Return the head of the list
    return head;
}

// Function to display the elements of the linked list
void display(Node *head)
{
    Node *start = head;  // Start from the head of the list
    while(start)         // Traverse the list until the end
    {
        printf("%d ", start->data);  // Print the data of the current node
        start = start->next;         // Move to the next node
    }
}

int main()
{
    int T, data;  // T: number of elements to insert, data: value of each element
    scanf("%d", &T);  // Read the number of elements
    Node *head = NULL;  // Initialize the head of the list as NULL
    
    // Loop to insert T elements into the linked list
    while(T-- > 0){
        scanf("%d", &data);  // Read the data for the new node
        head = insert(head, data);  // Insert the new node into the list
    }
    display(head);  // Display the elements of the linked list
}
