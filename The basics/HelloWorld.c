#include <stdio.h>

int main(void)
{    
    int x;      // variable declaration
    x = 5;      // variable initialization
    int y = 10; // variable declaration and initialization

    // %lf is a placeholder for a double value

    char name[] = "World";

    printf("Hello, %s!\n", name);           // %s is a placeholder for a string value


    printf("x = %d and y = %d \n", x, y);   // %d is a placeholder for an integer value

    return 0;
}

