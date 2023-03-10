#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int oppgave_1();
int oppgave_2();

typedef unsigned char BYTE;  // Nice to have

int main(int argc, char *argv[]) {

	for (int i = 1; i < argc; i++) {
		switch (atoi(argv[i])) {
			case 1:
				oppgave_1();
				break;
			case 2:
				oppgave_2();
				break;
			default:
				printf("You did not supply a valid option. \n Usage:\n %s <task>\n\n\r", argv[0]);
				break;
		}
	}
	    
    return 0;
}

// Read a text file full of double values and convert it into a binary file.
// Write code that converts it back to double values as a text file.
int oppgave_1() {

	// Declare stuff
	FILE *file = NULL;
	BYTE *buffer = NULL;
	char fileName[] = "doublesastext.txt"; // Could use a parameter for this later

	long lSize, bytesRead = 0;
	
    // Open file
    file = fopen(fileName, "rb");


	///////////////////////////////////////////////////////////////
	// Do some checks firts to avoid deeply nested if statements //
	///////////////////////////////////////////////////////////////
	
    // Check if file exists 
    if (file == NULL) {
        printf("Could not open file %s\n", fileName);
        return -1;
    } 
    printf("Succesfully opened %s\n", fileName);

    // Check if we are able to read to the end of the file at all
	if (fseek(file, 0, SEEK_END != 0)) {
		printf("Some error occurred reading the file...\n");
		return -1;
	}
	// ----------------------- END CHECKS ------------------------ //
	
	// First read through the whole file to see how much space we need
    if (fseek(file, 0, SEEK_END) == 0) {
    	lSize = ftell(file);
    }

    buffer = malloc(lSize * sizeof(BYTE));

    if (buffer == NULL) {
    	printf("Something went wrong allocating buffer...\n");
    	return -1;
    }

    bytesRead = fread(buffer, sizeof(BYTE), lSize, file);

	printf("Bytes read is %ld\n", bytesRead);
    BYTE *fileBuffer = malloc(bytesRead);

	double value;
	while(fscanf(file, "%lf", &value) == 1) {
		printf("%f\n", value);
	}
    
    // Done reading file

    // Convert to binary

	// Close the file
    free(buffer);
    fclose(file);
    return 0;
}

int oppgave_2() {
	printf("Not implemented yet...\n");
	return 0;
}
