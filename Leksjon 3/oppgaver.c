// We will look at usage of sizeof(). Please write a code that is going to output
// the sizes of various datatypes, pointers and static arrays.

// Hint : int, float, double, long, signed, unsigned, int *, float *, void *, int array[20]

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <stdarg.h>
#include <ctype.h>

// void err_n_die(const char *fmt, ...);

int err_no_exit(const char *fmt, ...);
int oppgave_1();
int oppgave_2();
int oppgave_3();

// run with gcc -Wall -o oppgaver oppgaver.c

int main(int argc, char **argv) 
{
    if (argc < 2)
    {
        err_no_exit("No arguments given. Printing all exercises. \r\n");
        oppgave_1();
    }

    char argument;
    argument = *argv[1];

    switch (argument)
    {
    case '1':
        oppgave_1();
        break;
    case '2':
        err_no_exit("Not a coding exercise\r\n"); // \r is carriage return, \n is newline, carriage return is used to move the cursor to the beginning of the line
        break;
    case '3':
        oppgave_3(argv);
        break;
    
    default:
        break;
    }
}

int check_valid_input(char iput[]) {
    if (atoi(iput) == 0) {
        printf("1; input is not a digit\r\n");
        return -1;
    }
    return 0;
}

int oppgave_3(char **argv) {
    int num;
    for (int i = 0; i < strlen(argv[2]); i++)
    {
        if (argv[2][0] == 48) { // 48 = ASCII 0 
            printf("Please provide a non-zero integer as argument!\n");
            return -1;
        }
        if (argv[2][i] < 48 || argv[2][i] > 57) {
            printf("You have entered at least one non-digit character: \033[0;31m%c\033[0m \r\n", argv[2][i]);
            printf("Please only provide integers as an argument!\n");
            return -1;
        }
        // printf("argv[2][%d]: %d\r\n", i, argv[2][i]);
    }

    char input[] = {*argv[2]};
    if (input[0] == 48) {
        printf("Please provide a non-zero integer as argument!\n");
        return 0;
    }
    
    if (isxdigit(input[0])) // 48 = ASCII 0
    { 
        if (check_valid_input(input) == 0)
        {
            num = atoi(argv[2]);
            printf("Number is %d\r\n", num);

            int isEven = num % 2 == 0 ? 1 : 0;
            char odd[5] = "odd\n";
            char even[6] = "even\n";
            printf("Number is %s", isEven == 1 ? even : odd);
        }
    }
    return 0;
}

int oppgave_2() {
    int x, y, z, w;

    x = 10;
    y = 9;
    z = 8;
    w = 7;

    if ((x == y++) && (z == ++x))
    {
        w = 100;
        printf("This is obviously true"); // false
    }

    z = ++w + y++; // z is probably going to be z(8) = 7 + 9 = 16
    // Correct answer is 18 - not sure how to test what get's executed first
    // But it makes sense to assume that ++w executes, and then y++, and then the values are added together

    printf("z = %d\n", z);
    
    return 0;
}

int oppgave_1()
{

    // sizeof int:
    printf("Size of int:            %ld bytes \n", sizeof(int));

    // sizeof float:
    printf("Size of float:          %ld bytes \r\n", sizeof(float));

    // sizeof double:
    printf("Size of double:         %ld bytes \r\n", sizeof(double));

    // sizeof long:
    printf("Size of long:           %ld bytes \r\n", sizeof(long));

    // sizeof signed:
    printf("Size of signed:         %ld bytes \r\n", sizeof(signed));

    // sizeof unsigned:
    printf("Size of unsigned:       %ld bytes \r\n", sizeof(unsigned));

    // sizeof int *:
    printf("Size of int *:          %ld bytes \r\n", sizeof(int *));

    // sizeof float *:
    printf("Size of float *:        %ld bytes \r\n", sizeof(float *));

    // sizeof void *:
    printf("Size of void *:         %ld bytes \r\n", sizeof(void *));
    
    // sizeof int array[20]:
    printf("Size of int array[20]:  %ld bytes \r\n", sizeof(int[20]));

    return 0;
}

// Error without exiting program
int err_no_exit(const char *fmt, ...) { // ... means that the function takes a variable number of arguments
    va_list args;
    va_start(args, fmt);
    vfprintf(stderr, fmt, args);
    va_end(args);
    return 1;
}