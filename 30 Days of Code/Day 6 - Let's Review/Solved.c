/*
Steps for the program:
1. Include necessary header files for input/output and string manipulation.
2. Define the `processString` function to process a string:
    a. Calculate the length of the string.
    b. Print characters at even indices followed by a space.
    c. Print characters at odd indices followed by a newline.
3. In the `main` function:
    a. Read the number of test cases (t).
    b. For each test case:
        i. Read the input string.
        ii. Call `processString` to process and print the string.
*/

#include <stdio.h>
#include <string.h>

void processString(char *str) {
    int len = strlen(str);
    // Print even-indexed characters
    for (int i = 0; i < len; i += 2) {
        printf("%c", str[i]);
    }
    printf(" ");
    // Print odd-indexed characters
    for (int i = 1; i < len; i += 2) {
        printf("%c", str[i]);
    }
    printf("\n");
}

int main() {
    int t;
    scanf("%d", &t);
    char str[10000];
    for (int i = 0; i < t; i++) {
        scanf("%s", str);
        processString(str);
    }
    return 0;
}