/*

Steps for the program:

1. Include the standard input-output library using #include <stdio.h>.
2. Define the main function where the program execution begins.
3. Declare and initialize three variables:
    - An integer `i` with a value of 4.
    - A double `d` with a value of 4.0.
    - A string `s` initialized to "HackerRank ".
4. Declare three additional variables to store user input:
    - An integer `j`.
    - A double `e`.
    - A character array `t` to store a string.
5. Use `scanf` to read an integer and a double from the user and store them in `j` and `e`, respectively.
6. Use `getchar` to clear the newline character left in the input buffer after reading the double.
7. Use `scanf` with the format specifier `%[^\n]` to read a string (including spaces) from the user and store it in `t`.
8. Compute and print the sum of the integers `i` and `j` on a new line.
9. Compute and print the sum of the doubles `d` and `e` with one decimal precision on a new line.
10. Concatenate the string `s` with the user-provided string `t` and print the result on a new line.
11. Return 0 to indicate successful program execution.
*/

#include <stdio.h>

int main()
{
    int i = 4;
    double d = 4.0;
    char s[] = "HackerRank ";

    // Declare second integer, double, and String variables.
    int j;
    double e;
    char t[100];

    // Read and save an integer, double, and String to your variables.
    scanf("%d", &j);
    scanf("%lf", &e);
    getchar(); // Clear the newline character from the input buffer
    // Read the string input
    // Use %s to read a string until whitespace
    // Use %[^\n] to read until a newline character
    // This is useful for reading strings with spaces
    scanf("%[^\n]", t);
    
    // Print the sum of both integer variables on a new line.
    printf("%d\n", i + j);
    printf("%.1lf\n", d + e);

    // Concatenate and print the String variables on a new line
    printf("%s%s\n", s, t);

    return 0;
}
