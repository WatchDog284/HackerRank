/**
 * This program determines whether a given integer `N` is "Weird" or "Not Weird"
 * based on specific conditions. Below are the steps performed in the program:
 *
 * 1. Read an integer input `N` from the user.
 * 2. Check if `N` is odd:
 *    - If `N` is odd, print "Weird".
 * 3. If `N` is even, evaluate the following conditions in order:
 *    - If `N` is in the range [2, 5], print "Not Weird".
 *    - If `N` is in the range [6, 20], print "Weird".
 *    - If `N` is greater than 20, print "Not Weird".
 * 4. The conditions are evaluated in the order of precedence to ensure the correct
 *    output is printed.
 * 5. Helper functions are used to handle input processing:
 *    - `readline()` reads a line of input from the user.
 *    - `ltrim()` trims leading whitespace from a string.
 *    - `rtrim()` trims trailing whitespace from a string.
 *    - `parse_int()` converts a string to an integer and exits the program if the
 *      conversion fails.
 */

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

char* readline();
char* ltrim(char*);
char* rtrim(char*);
int parse_int(char*);

int main()
{
    int N = parse_int(ltrim(rtrim(readline())));

    // Check if N is odd
    // If N is odd, print "Weird"
    // If N is even, check the range and print accordingly
    // If N is even and in the range [2, 5], print "Not Weird"
    // If N is even and in the range [6, 20], print "Weird"
    // If N is even and greater than 20, print "Not Weird"
    // The conditions are checked in the order of precedence
    // to ensure the correct output is printed
    // The first condition checks if N is odd

    if (N % 2 != 0) {
        printf("Weird\n");
    } else if (N >= 2 && N <= 5) {
        printf("Not Weird\n");
    } else if (N >= 6 && N <= 20) {
        printf("Weird\n");
    } else {
        printf("Not Weird\n");
    }

    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;

    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) {
            break;
        }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') {
            break;
        }

        alloc_length <<= 1;

        data = realloc(data, alloc_length);

        if (!data) {
            data = '\0';

            break;
        }
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';

        data = realloc(data, data_length);

        if (!data) {
            data = '\0';
        }
    } else {
        data = realloc(data, data_length + 1);

        if (!data) {
            data = '\0';
        } else {
            data[data_length] = '\0';
        }
    }

    return data;
}

char* ltrim(char* str) {
    if (!str) {
        return '\0';
    }

    if (!*str) {
        return str;
    }

    while (*str != '\0' && isspace(*str)) {
        str++;
    }

    return str;
}

char* rtrim(char* str) {
    if (!str) {
        return '\0';
    }

    if (!*str) {
        return str;
    }

    char* end = str + strlen(str) - 1;

    while (end >= str && isspace(*end)) {
        end--;
    }

    *(end + 1) = '\0';

    return str;
}

int parse_int(char* str) {
    char* endptr;
    int value = strtol(str, &endptr, 10);

    if (endptr == str || *endptr != '\0') {
        exit(EXIT_FAILURE);
    }

    return value;
}