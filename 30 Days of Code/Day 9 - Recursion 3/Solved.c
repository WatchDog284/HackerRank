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

// Function declarations for helper functions
char* readline();
char* ltrim(char*);
char* rtrim(char*);
int parse_int(char*);

/*
 * Recursive function to calculate the factorial of a number.
 * Base case: If n <= 1, return 1.
 * Recursive case: Return n * factorial(n - 1).
 */
int factorial(int n) {
    if (n <= 1) {
        return 1; // Base case
    }
    return n * factorial(n - 1); // Recursive case
}

int main() {
    // Open the output file specified by the OUTPUT_PATH environment variable
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    // Read input, trim whitespace, and parse it into an integer
    int n = parse_int(ltrim(rtrim(readline())));

    // Calculate the factorial of the input number
    int result = factorial(n);

    // Write the result to the output file
    fprintf(fptr, "%d\n", result);

    // Close the output file
    fclose(fptr);

    return 0; // Exit the program
}

/*
 * Reads a line of input from standard input dynamically.
 * Handles memory allocation and resizing as needed.
 */
char* readline() {
    size_t alloc_length = 1024; // Initial buffer size
    size_t data_length = 0; // Current length of the input

    char* data = malloc(alloc_length); // Allocate memory for the input

    while (true) {
        char* cursor = data + data_length; // Pointer to the current position in the buffer
        char* line = fgets(cursor, alloc_length - data_length, stdin); // Read input

        if (!line) { // Break if no more input
            break;
        }

        data_length += strlen(cursor); // Update the length of the input

        // Break if the input fits in the buffer or ends with a newline
        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') {
            break;
        }

        // Double the buffer size if needed
        alloc_length <<= 1;
        data = realloc(data, alloc_length);

        if (!data) { // Handle memory allocation failure
            data = '\0';
            break;
        }
    }

    // Remove the trailing newline character, if present
    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';
        data = realloc(data, data_length); // Resize buffer to fit the input
        if (!data) { // Handle memory allocation failure
            data = '\0';
        }
    } else {
        data = realloc(data, data_length + 1); // Add null terminator
        if (!data) { // Handle memory allocation failure
            data = '\0';
        } else {
            data[data_length] = '\0';
        }
    }

    return data; // Return the input string
}

/*
 * Removes leading whitespace from a string.
 */
char* ltrim(char* str) {
    if (!str) { // Handle null input
        return '\0';
    }

    if (!*str) { // Handle empty string
        return str;
    }

    // Skip leading whitespace characters
    while (*str != '\0' && isspace(*str)) {
        str++;
    }

    return str; // Return the trimmed string
}

/*
 * Removes trailing whitespace from a string.
 */
char* rtrim(char* str) {
    if (!str) { // Handle null input
        return '\0';
    }

    if (!*str) { // Handle empty string
        return str;
    }

    char* end = str + strlen(str) - 1; // Pointer to the last character

    // Move the pointer backward while there are trailing whitespace characters
    while (end >= str && isspace(*end)) {
        end--;
    }

    *(end + 1) = '\0'; // Null-terminate the string

    return str; // Return the trimmed string
}

/*
 * Converts a string to an integer.
 * Exits the program if the string is not a valid integer.
 */
int parse_int(char* str) {
    char* endptr;
    int value = strtol(str, &endptr, 10); // Convert string to integer

    // Check if the conversion was successful
    if (endptr == str || *endptr != '\0') {
        exit(EXIT_FAILURE); // Exit if the string is not a valid integer
    }

    return value; // Return the parsed integer
}
