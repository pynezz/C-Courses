#include <stdio.h>
#include <stdlib.h>

int oppgave_1();
int oppgave_2();

int main(int argc, char *argv[]) {
	if (argc < 2) {
		printf("Usage: %s <task>\n\r\n", argv[0]);
		return 0;
	}

	char argument;
	argument = *argv[1];

	for (int i = 1; i < argc; i++) {
		switch (atoi(argv[i])) {
			case 1:
				for (int i = 0; i < 3; i++) {
				
					oppgave_1();
				}
				break;
			case 2:
				oppgave_2();
				break;
		}
	} 

	return 0;
}

// Write a function, that can print how many times it has been called so far
// without using a global variable
int oppgave_1() {
	static int iCalls;

	iCalls++;

	printf("Calls: %d\n", iCalls); 

	return 0;
}

int oppgave_2() {
	printf("Not implemented yet\n");

	return 0;
}
