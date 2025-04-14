#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
    char inputString[100];

    scanf("%[^\n]", inputString);
    // Print a string literal saying "Hello, World." on the first line.

    printf("Hello, World.\n");
    printf("%s",inputString); 

    return 0;
}