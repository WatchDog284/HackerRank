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

/*
 * Complete the 'weightedMean' function below.
 *
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY X
 *  2. INTEGER_ARRAY W
 */
void weightedMean(int X_count, int* X, int W_count, int* W) {
    // Check if the sizes of the two arrays are equal
    if (X_count != W_count) {
        return;
    }
    
    // Initialize variables for weighted sum and total weight
    int weightedSum = 0, weightedTotal = 0;

    // Calculate the weighted sum and total weight
    for (int i = 0; i < X_count; i++) {
        weightedSum += X[i] * W[i];
        weightedTotal += W[i];
    }
    
    // Compute the weighted mean and print it with one decimal precision
    double weightedMean = (double)weightedSum / weightedTotal;
    printf("%.1f\n", weightedMean);
}

int main() {
    // Read the size of the arrays
    int n = parse_int(ltrim(rtrim(readline())));

    // Read the values array as a space-separated string
    char** vals_temp = split_string(rtrim(readline()));

    // Allocate memory for the values array
    int* vals = malloc(n * sizeof(int));

    // Parse the values array from the input
    for (int i = 0; i < n; i++) {
        int vals_item = parse_int(*(vals_temp + i));
        *(vals + i) = vals_item;
    }

    // Read the weights array as a space-separated string
    char** weights_temp = split_string(rtrim(readline()));

    // Allocate memory for the weights array
    int* weights = malloc(n * sizeof(int));

    // Parse the weights array from the input
    for (int i = 0; i < n; i++) {
        int weights_item = parse_int(*(weights_temp + i));
        *(weights + i) = weights_item;
    }

    // Call the weightedMean function to compute and print the result
    weightedMean(n, vals, n, weights);

    return 0;
}

// Reads a line of input from stdin
char* readline() {
    size_t alloc_length = 1024; // Initial buffer size
    size_t data_length = 0;    // Current length of the data

    char* data = malloc(alloc_length); // Allocate memory for the buffer

    while (true) {
        char* cursor = data + data_length; // Pointer to the current position in the buffer
        char* line = fgets(cursor, alloc_length - data_length, stdin); // Read input

        if (!line) { // Break if no input is read
            break;
        }

        data_length += strlen(cursor); // Update the data length

        // Break if the buffer is not full or a newline is encountered
        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') {
            break;
        }

        // Double the buffer size if it's full
        alloc_length <<= 1;
        data = realloc(data, alloc_length);

        if (!data) { // Handle memory allocation failure
            data = '\0';
            break;
        }
    }

    // Replace the newline character with a null terminator
    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';
        data = realloc(data, data_length); // Shrink the buffer to fit the data

        if (!data) { // Handle memory allocation failure
            data = '\0';
        }
    } else {
        data = realloc(data, data_length + 1); // Add space for the null terminator

        if (!data) { // Handle memory allocation failure
            data = '\0';
        } else {
            data[data_length] = '\0'; // Add the null terminator
        }
    }

    return data;
}

// Trims leading whitespace from a string
char* ltrim(char* str) {
    if (!str) { // Return null if the input is null
        return '\0';
    }

    if (!*str) { // Return the string if it's empty
        return str;
    }

    // Move the pointer forward while whitespace is encountered
    while (*str != '\0' && isspace(*str)) {
        str++;
    }

    return str;
}

// Trims trailing whitespace from a string
char* rtrim(char* str) {
    if (!str) { // Return null if the input is null
        return '\0';
    }

    if (!*str) { // Return the string if it's empty
        return str;
    }

    // Find the end of the string
    char* end = str + strlen(str) - 1;

    // Move the pointer backward while whitespace is encountered
    while (end >= str && isspace(*end)) {
        end--;
    }

    *(end + 1) = '\0'; // Add a null terminator

    return str;
}

// Splits a string into an array of tokens based on spaces
char** split_string(char* str) {
    char** splits = NULL; // Initialize the array of tokens
    char* token = strtok(str, " "); // Get the first token

    int spaces = 0; // Count the number of tokens

    // Loop through the tokens
    while (token) {
        splits = realloc(splits, sizeof(char*) * ++spaces); // Reallocate memory for the array

        if (!splits) { // Handle memory allocation failure
            return splits;
        }

        splits[spaces - 1] = token; // Store the token in the array
        token = strtok(NULL, " "); // Get the next token
    }

    return splits;
}

// Parses an integer from a string
int parse_int(char* str) {
    char* endptr;
    int value = strtol(str, &endptr, 10); // Convert the string to an integer

    if (endptr == str || *endptr != '\0') { // Handle invalid input
        exit(EXIT_FAILURE);
    }

    return value;
}
