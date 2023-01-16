#include <stdio.h>

int main(void)
{    
    int x;      // variable declaration
    x = 5;      // variable initialization
    int y = 10; // variable declaration and initialization

    char name[] = "World";

    printf("Hello, %s!\n", name);           // %s is a placeholder for a string value
    
    // %f is a placeholder for a floating point value
    // %d is a placeholder for an integer value
    // %c is a placeholder for a character value
    // %s is a placeholder for a string value

    // %p is a placeholder for a pointer value
    // %x is a placeholder for a hexadecimal value

    // %o is a placeholder for an octal value
    // %e is a placeholder for a floating point value in scientific notation
    // %g is a placeholder for a floating point value in scientific notation or decimal notation
    // %u is a placeholder for an unsigned integer value
    // %n is a placeholder for the number of characters printed so far
    // %%% is a placeholder for a percent sign

    printf("x = %d and y = %d \n", x, y);   // %d is a placeholder for an integer value

    return 0;
}

