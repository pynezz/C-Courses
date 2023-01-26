// We will look at usage of sizeof(). Please write a code that is going to output
// the sizes of various datatypes, pointers and static arrays.

// Hint : int, float, double, long, signed, unsigned, int *, float *, void *, int array[20]

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <stdarg.h>



// err_n_die:
// Print error message but do not exit.
void err_n_die(const char *fmt, ...) {
    int errno_save;
    va_list ap;

    errno_save = errno; // value caller might want printed

    va_start(ap, fmt);
    vfprintf(stderr, fmt, ap);
    fprintf(stderr, " \r ");
    fflush(stderr);

    if (errno_save != 0) {
        fprintf(stderr, "(errno = %d) : %s \r ", errno_save, strerror(errno_save));
        fprintf(stderr, " \r ");
        fflush(stderr);
    }

    va_end(ap);
    return;
}


// run with gcc -Wall -o oppgaver oppgaver.c

void oppgave_1() {
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
    
    return;
}


int main(int argc, char **argv)
{      
    if (argc < 2) {
        err_n_die("No arguments given. Printing all exercises. \r\n");
        oppgave_1();
    }

    if (strcmp(argv[1], "1") == 0) {
        oppgave_1();
        err_n_die("Done. \r ");
    }

    return 0;    
}