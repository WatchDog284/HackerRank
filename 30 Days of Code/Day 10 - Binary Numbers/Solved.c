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

// Function declarations
char* readline(); // Reads a line of input from stdin
char* ltrim(char*); // Trims leading whitespace from a string
char* rtrim(char*); // Trims trailing whitespace from a string
int parse_int(char*); // Parses a string into an integer

int main()
{
    // Read an integer input, trimming any leading/trailing whitespace
    int n = parse_int(ltrim(rtrim(readline())));

    int max_consecutive_ones = 0; // Variable to store the maximum number of consecutive 1s in binary representation
    int current_count = 0; // Variable to count the current streak of consecutive 1s

    // Loop to process the binary representation of the number
    while (n > 0) {
        if (n % 2 == 1) { // Check if the least significant bit is 1
            current_count++; // Increment the current streak of 1s
            if (current_count > max_consecutive_ones) { // Update the maximum streak if needed
                max_consecutive_ones = current_count;
            }
        } else {
            current_count = 0; // Reset the current streak if the bit is 0
        }
        n /= 2; // Right shift the number by dividing it by 2
    }

    // Print the maximum number of consecutive 1s
    printf("%d\n", max_consecutive_ones);

    return 0;
}

// Function to read a line of input from stdin
char* readline() {
    size_t alloc_length = 1024; // Initial buffer size
    size_t data_length = 0; // Current length of the data read

    char* data = malloc(alloc_length); // Allocate memory for the buffer

    while (true) {
        char* cursor = data + data_length; // Pointer to the current position in the buffer
        char* line = fgets(cursor, alloc_length - data_length, stdin); // Read input into the buffer

        if (!line) { // Break if no input is read
            break;
        }

        data_length += strlen(cursor); // Update the length of the data read

        // Break if the buffer is not full or a newline is encountered
        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') {
            break;
        }

        alloc_length <<= 1; // Double the buffer size
        data = realloc(data, alloc_length); // Reallocate memory for the buffer

        if (!data) { // Handle memory allocation failure
            data = '\0';
            break;
        }
    }

    // Remove the trailing newline character, if present
    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';
        data = realloc(data, data_length); // Shrink the buffer to fit the data
        if (!data) { // Handle memory allocation failure
            data = '\0';
        }
    } else {
        data = realloc(data, data_length + 1); // Ensure null-termination
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

    // Move the pointer forward while encountering whitespace
    while (*str != '\0' && isspace(*str)) {
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

    char* end = str + strlen(str) - 1; // Pointer to the last character of the string

    // Move the pointer backward while encountering whitespace
    while (end >= str && isspace(*end)) {
        end--;
    }

    *(end + 1) = '\0'; // Null-terminate the string after the last non-whitespace character

    return str; // Return the trimmed string
}

// Function to parse a string into an integer
int parse_int(char* str) {
    char* endptr; // Pointer to track invalid characters
    int value = strtol(str, &endptr, 10); // Convert the string to an integer

    // Exit if the string is not a valid integer
    if (endptr == str || *endptr != '\0') {
        exit(EXIT_FAILURE);
    }

    return value; // Return the parsed integer
}