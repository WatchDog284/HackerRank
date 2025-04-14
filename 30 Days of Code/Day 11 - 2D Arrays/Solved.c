#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function declarations for utility functions
char* readline();
char* ltrim(char*);
char* rtrim(char*);
char** split_string(char*);
int parse_int(char*);

int main() {
    // Allocate memory for a 6x6 2D array
    int** arr = malloc(6 * sizeof(int*));

    // Read input for the 6x6 array
    for (int i = 0; i < 6; i++) {
        *(arr + i) = malloc(6 * (sizeof(int))); // Allocate memory for each row

        char** arr_item_temp = split_string(rtrim(readline())); // Read and split the input line

        for (int j = 0; j < 6; j++) {
            int arr_item = parse_int(*(arr_item_temp + j)); // Parse each integer from the input
            *(*(arr + i) + j) = arr_item; // Store the integer in the 2D array
        }
    }

    int maxSum = INT_MIN; // Initialize the maximum hourglass sum to the smallest possible integer

    // Calculate the maximum hourglass sum
    for (int i = 0; i < 4; i++) { // Loop through rows where hourglass can start
        for (int j = 0; j < 4; j++) { // Loop through columns where hourglass can start
            // Calculate the sum of the current hourglass
            int hourglassSum = *(*(arr + i) + j) + *(*(arr + i) + j + 1) + *(*(arr + i) + j + 2) // Top row of hourglass
                             + *(*(arr + i + 1) + j + 1) // Middle element of hourglass
                             + *(*(arr + i + 2) + j) + *(*(arr + i + 2) + j + 1) + *(*(arr + i + 2) + j + 2); // Bottom row of hourglass
            if (hourglassSum > maxSum) { // Update maxSum if the current hourglass sum is greater
                maxSum = hourglassSum;
            }
        }
    }

    // Output the maximum hourglass sum
    printf("%d\n", maxSum);

    // Free allocated memory for the 2D array
    for (int i = 0; i < 6; i++) {
        free(*(arr + i)); // Free each row
    }
    free(arr); // Free the array of pointers

    return 0;
}

// Function to read a line of input from stdin
char* readline() {
    size_t alloc_length = 1024; // Initial buffer size
    size_t data_length = 0; // Current length of the data

    char* data = malloc(alloc_length); // Allocate memory for the buffer

    while (true) {
        char* cursor = data + data_length; // Pointer to the current position in the buffer
        char* line = fgets(cursor, alloc_length - data_length, stdin); // Read input into the buffer

        if (!line) { // Break if no input is read
            break;
        }

        data_length += strlen(cursor); // Update the length of the data

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') { // Break if the line is complete
            break;
        }

        alloc_length <<= 1; // Double the buffer size
        data = realloc(data, alloc_length); // Reallocate memory for the buffer

        if (!data) { // Handle memory allocation failure
            data = '\0';
            break;
        }
    }

    if (data[data_length - 1] == '\n') { // Remove the trailing newline character
        data[data_length - 1] = '\0';
        data = realloc(data, data_length); // Shrink the buffer to fit the data
        if (!data) { // Handle memory allocation failure
            data = '\0';
        }
    } else {
        data = realloc(data, data_length + 1); // Ensure the buffer is null-terminated
        if (!data) { // Handle memory allocation failure
            data = '\0';
        } else {
            data[data_length] = '\0';
        }
    }

    return data; // Return the input string
}

// Function to trim leading whitespace from a string
char* ltrim(char* str) {
    if (!str) { // Return null if the input is null
        return '\0';
    }

    if (!*str) { // Return the string if it's empty
        return str;
    }

    while (*str != '\0' && isspace(*str)) { // Skip leading whitespace
        str++;
    }

    return str; // Return the trimmed string
}

// Function to trim trailing whitespace from a string
char* rtrim(char* str) {
    if (!str) { // Return null if the input is null
        return '\0';
    }

    if (!*str) { // Return the string if it's empty
        return str;
    }

    char* end = str + strlen(str) - 1; // Pointer to the end of the string

    while (end >= str && isspace(*end)) { // Skip trailing whitespace
        end--;
    }

    *(end + 1) = '\0'; // Null-terminate the string

    return str; // Return the trimmed string
}

// Function to split a string into an array of strings based on spaces
char** split_string(char* str) {
    char** splits = NULL; // Array to store the split strings
    char* token = strtok(str, " "); // Tokenize the string using space as a delimiter

    int spaces = 0; // Count of tokens

    while (token) {
        splits = realloc(splits, sizeof(char*) * ++spaces); // Reallocate memory for the array

        if (!splits) { // Handle memory allocation failure
            return splits;
        }

        splits[spaces - 1] = token; // Store the token in the array
        token = strtok(NULL, " "); // Get the next token
    }

    return splits; // Return the array of split strings
}

// Function to parse an integer from a string
int parse_int(char* str) {
    char* endptr;
    int value = strtol(str, &endptr, 10); // Convert the string to an integer

    if (endptr == str || *endptr != '\0') { // Exit if the string is not a valid integer
        exit(EXIT_FAILURE);
    }

    return value; // Return the parsed integer
}