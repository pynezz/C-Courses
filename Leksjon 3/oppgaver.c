#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <stdarg.h>
#include <ctype.h>
#include <time.h>

int err_no_exit(const char *fmt, ...);
int oppgave_1();
int oppgave_2();
int oppgave_3();
int oppgave_4();
int oppgave_5();

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
    case '4':
        oppgave_4();
        break;
    case '5':
        oppgave_5();
        break;

    default:
        break;
    }
}

int oppgave_5() {

    // goto block_1;
// Exercise 5:

// Convert these blocks accordingly :

// -------------------------------
// #include <time.h>
// #include <stdlib.h>

// Block 1(to switch):
// {
//    srand(time(NULL))
//    int a = rand()%20;
//    if(a == 1){
//       printf("%d is 1", a);}
//    else if(a%2 == 0){
//       printf("%d is not a prime", a);}
//    else if(a%3 == 0){
//       printf("%d is not a prime", a);}
//    else if(a%5 == 0){
//       printf("%d is not a prime", a);}
//    else if(a%7 == 0){
//       printf("%d is not a prime", a);}
//    else if(a%11 == 0){
//       printf("%d is not a prime", a);}
//    else if(a%13 == 0){
//       printf("%d is not a prime", a);}
//    else if(a%17 == 0){
//       printf("%d is not a prime", a);}
//    else if(a%19 == 0){
//       printf("%d is not a prime", a);}
//    else{
//       printf("%d is a prime", a);
//    }

// }

    // Block 1(to switch):
    printf("\nThe non-working code:\n");

    srand(time(NULL));
    int a = rand() % 20;
    printf("Number is %d\n", a);
    if (a == 1)
    {
        printf("%d is 1, redoing...", a);
        oppgave_5();
    }
    else if (a % 2 == 0)
    {
        printf("%d is not a prime", a);
    }
    else if (a % 3 == 0)
    {
        printf("%d is not a prime", a);
    }
    else if (a % 5 == 0)
    {
        printf("%d is not a prime", a);
    }
    else if (a % 7 == 0)
    {
        printf("%d is not a prime", a);
    }
    else if (a % 11 == 0)
    {
        printf("%d is not a prime", a);
    }
    else if (a % 13 == 0)
    {
        printf("%d is not a prime", a);
    }
    else if (a % 17 == 0)
    {
        printf("%d is not a prime", a);
    }
    else if (a % 19 == 0)
    {
        printf("%d is not a prime", a);
    }
    else
    {
        printf("%d is a prime", a);
    }
    printf("\n"); // Added this instead of editing every line above

    // Primes below 20: 2, 3, 5, 7, 11, 13, 17, 19

    // I want prime numbers, But this does not give primes to me. What should
    // I change to get to the last printf when a is a prime number?

    // YES THIS IS A "TRICK-QUESTION" ASIGNMENT - Why doesnt the above code work as it should?
    // Write the correct code that outputs if a number is a prime number or not :-)

    printf("\n------------\n\nThe working code:\n");

    srand(time(NULL));
    a = rand() % 20;
    printf("Number is %d\n", a);
    int factorials = 0;
    // if (a == 1) {
    //     printf("%d is 1, redoing...", a);
    //     oppgave_5();
    // } 

    // Doing this instead of a bunch of if statements
    for (int i = 2; i < 20; i++) {
        if (a % i == 0) {
            factorials++;
        }
    }

    if (factorials == 1) {
        printf("\033[0;32m%d is a prime\033[0m\n\n", a);
    } else {
        printf("\033[0;31m%d is not a prime\033[0m\n\n", a);
    }

    return 0;

    // Output for 13: 
    // The non-working code:
    // Number is 13
    // 13 is a prime

    // ------------
    // The working code:
    // Number is 13
    // 13 is a prime
    
}

int oppgave_4() { // Bottles of beer
    int bottles_of_beer = 99;
    while (bottles_of_beer > 1)
    {
        printf("\n%d bottles of beer on the wall, %d bottles of beer.\nTake one down and pass it around, %d bottles of beer on the wall.\r\n", bottles_of_beer, bottles_of_beer, bottles_of_beer - 1);
        bottles_of_beer--;
    }

    printf("\n%d bottle of beer on the wall, %d bottle of beer.\nTake one down and pass it around, no more bottles of beer on the wall.\r\n", bottles_of_beer, bottles_of_beer);
    printf("\nNo more bottles of beer on the wall, no more bottles of beer.\nWe've taken them down and passed them around; now we're drunk and passed out!\n");
    return 0;
}

int check_valid_input(char iput[]) { // Helper function for oppgave_3
    if (atoi(iput) == 0) {
        printf("1; input is not a digit\r\n");
        return -1;
    }
    return 0;
}

int oppgave_3(char **argv) { // Even or odd
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

int oppgave_2() { // Not a coding exercise
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

int oppgave_1() // Sizes of datatypes
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