#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main() {
    oppgave_1();

    return 0;
}

// Read a text file full of double values and convert it into a binary file.
// Write code that converts it back to double values as a text file.
int oppgave_1() {
    // Read file
    FILE *file = fopen("doublesastext.txt", "r");

    //////////////////////////
    // Check if file exists //
    //////////////////////////
    if (file == NULL) {
        printf("Could not open file");
        return 1;
    }



}
