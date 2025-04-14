// This is an optimized version of the code for faster execution

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_ENTRIES 100000
#define HASH_SIZE 200003  // A large prime for better hashing

typedef struct {
    char name[50];
    char phone[20];
} PhoneBookEntry;

PhoneBookEntry *hashTable[HASH_SIZE] = {NULL};

// Simple hash function
unsigned long hash(const char *str) {
    // Step 1: Initialize hash value to 0
    unsigned long hash = 0;
    // Step 2: Iterate through each character of the string
    while (*str)
        // Step 3: Update hash value using a multiplier (31) and the character
        hash = (hash * 31) + *str++;
    // Step 4: Return the hash value modulo HASH_SIZE
    return hash % HASH_SIZE;
}

// Insert into hash table
void insert(const char *name, const char *phone) {
    // Step 1: Compute the hash index for the given name
    unsigned long index = hash(name);
    // Step 2: Handle collisions using linear probing
    while (hashTable[index] != NULL)
        index = (index + 1) % HASH_SIZE;

    // Step 3: Allocate memory for a new PhoneBookEntry
    hashTable[index] = malloc(sizeof(PhoneBookEntry));
    // Step 4: Copy the name and phone number into the allocated entry
    strcpy(hashTable[index]->name, name);
    strcpy(hashTable[index]->phone, phone);
}

// Search for a name
const char* search(const char *name) {
    // Step 1: Compute the hash index for the given name
    unsigned long index = hash(name);
    // Step 2: Traverse the hash table using linear probing
    while (hashTable[index] != NULL) {
        // Step 3: Check if the current entry matches the name
        if (strcmp(hashTable[index]->name, name) == 0)
            // Step 4: Return the phone number if a match is found
            return hashTable[index]->phone;
        index = (index + 1) % HASH_SIZE;
    }
    // Step 5: Return NULL if the name is not found
    return NULL;
}

int main() {
    int n;
    // Step 1: Read the number of entries to be added to the phone book
    scanf("%d", &n);

    char name[50], phone[20];
    // Step 2: Loop through the input to read names and phone numbers
    for (int i = 0; i < n; i++) {
        scanf("%s %s", name, phone);
        // Step 3: Insert each name and phone number into the hash table
        insert(name, phone);
    }

    char query[50];
    // Step 4: Process queries until end of input
    while (scanf("%s", query) != EOF) {
        // Step 5: Search for the queried name in the hash table
        const char *result = search(query);
        // Step 6: Print the result if found, otherwise print "Not found"
        if (result)
            printf("%s=%s\n", query, result);
        else
            printf("Not found\n");
    }

    // Step 7: Free all allocated memory in the hash table
    for (int i = 0; i < HASH_SIZE; i++)
        if (hashTable[i] != NULL)
            free(hashTable[i]);

    return 0;
}