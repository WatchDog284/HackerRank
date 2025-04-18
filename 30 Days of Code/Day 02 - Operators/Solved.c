/**
 * This program calculates the total cost of a meal, including tip and tax, 
 * and prints the rounded total cost. Below are the steps performed by the program:
 *
 * 1. Read the meal cost, tip percentage, and tax percentage as input from the user.
 * 2. Parse the input values to their respective data types:
 *    - `meal_cost` is parsed as a double.
 *    - `tip_percent` and `tax_percent` are parsed as integers.
 * 3. Pass the parsed values to the `solve` function.
 * 4. Inside the `solve` function:
 *    - Calculate the tip amount as `(meal_cost * tip_percent) / 100`.
 *    - Calculate the tax amount as `(meal_cost * tax_percent) / 100`.
 *    - Compute the total cost by summing `meal_cost`, `tip`, and `tax`.
 *    - Round the total cost to the nearest integer and print it.
 * 5. Utility functions are provided for:
 *    - Reading input (`readline`).
 *    - Trimming leading and trailing whitespace (`ltrim` and `rtrim`).
 *    - Parsing strings to double and integer values (`parse_double` and `parse_int`).
 * 6. The program ensures proper memory allocation and handles invalid input by exiting with an error.
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

double parse_double(char*);
int parse_int(char*);

/*
 * Complete the 'solve' function below.
 *
 * The function accepts following parameters:
 *  1. DOUBLE meal_cost
 *  2. INTEGER tip_percent
 *  3. INTEGER tax_percent
 */
void solve(double meal_cost, int tip_percent, int tax_percent) {
    
    double tip = (meal_cost * tip_percent) / 100;
    double tax = (tax_percent * meal_cost) / 100;
    double total_cost = meal_cost + tip + tax;
    printf("%.0f\n", round(total_cost));
}

int main()
{
    double meal_cost = parse_double(ltrim(rtrim(readline())));

    int tip_percent = parse_int(ltrim(rtrim(readline())));

    int tax_percent = parse_int(ltrim(rtrim(readline())));

    solve(meal_cost, tip_percent, tax_percent);

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

double parse_double(char* str) {
    char* endptr;
    double value = strtod(str, &endptr);

    if (endptr == str || *endptr != '\0') {
        exit(EXIT_FAILURE);
    }

    return value;
}

int parse_int(char* str) {
    char* endptr;
    int value = strtol(str, &endptr, 10);

    if (endptr == str || *endptr != '\0') {
        exit(EXIT_FAILURE);
    }

    return value;
}
