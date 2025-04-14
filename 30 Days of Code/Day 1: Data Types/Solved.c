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
