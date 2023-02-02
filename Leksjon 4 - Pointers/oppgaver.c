#include <stdio.h>
#include <stdlib.h>

int main(int *argc, char **argv) {
    int *p = malloc(sizeof(int));
    *p = 10;
    printf("%d", *p);
    free(p);
    return 0;
}


// Oppgave 5
// Expected output:
// ex5 hallo on the bath you old candybar
// Number of strings: 7
// 1: hallo
// 2: on
// 3: the
// 4: bath
// 5: you
// 6: old
// 7: candybar
void oppgave_5() {

}

// Use strcmpr to compare two strings and sort them alphabetically


