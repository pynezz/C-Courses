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

int oppgave_1(); 

// run with gcc -Wall -o oppgaver oppgaver.c

int main(int argc, char **argv) 
{
    int num;

    char input[] = {*argv[1]};
    // printf("10 is equal to %d bytes, and argv[1] is %d bytes", sizeof(10), sizeof(input[0]));
    if ((isxdigit(input[0]), 2) && (input[0] != 48))
    { // 48 = ASCII 0
        printf("input is digit\n");
        if (check_valid_input(argv[1]) >= 0)
        {
            num = atoi(argv[1]);
            int isEven = num % 2 == 0 ? 1 : 0;
            char odd[14] = "odd\n";
            char even[15] = "even\n";
            printf("Number is %s", isEven == 1 ? even : odd);
        } else printf("please provide a non-zero integer as argument!\n");
        // return isEven ? "Number is even" : "Number is odd";
    }
    else
        printf("please provide a non-zero integer as argument!\n");

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

    printf("z = %d\n", z);
    printf("Next!\n");

    if (argc < 2)
    {
        // err_n_die("No arguments given. Printing all exercises. \r\n");
        oppgave_1();
    }

    if (strcmp(argv[1], "1") == 0)
    {
        oppgave_1();
        // err_n_die("Done. \r ");
    }

    return 0;
}

int check_valid_input(char input[]) {
    for (int i = 0; i < sizeof(input) / sizeof(char); i++) {
        if (!isdigit(input[i])) {
            return -1;
        }
    }
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

// err_n_die:
// Print error message but do not exit.
// void err_n_die(const char *fmt, ...) {
//     int errno_save;
//     va_list ap;

//     errno_save = errno; // value caller might want printed

//     va_start(ap, fmt);
//     vfprintf(stderr, fmt, ap);
//     fprintf(stderr, " \r ");
//     fflush(stderr);

//     if (errno_save != 0) {
//         fprintf(stderr, "(errno = %d) : %s \r ", errno_save, strerror(errno_save));
//         fprintf(stderr, " \r ");
//         fflush(stderr);
//     }

//     va_end(ap);
//     return;
// }