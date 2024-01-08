#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Including the utility and poly files
#include "utils.h"
#include "poly.h"

int main(int argc, char *argv[]) {
	//Making sure that the input is ok
	if (argc != 2) {
		printf("Please check command line input.\n");
		return 1;
	}
	//Open the file and make sure it exists
	FILE *file = fopen(argv[1], "rt");
	if (file == NULL) {
		printf("File does not exist.\n");
		return 1;
	}
	//Extract coeff and expo from file and add to polynomial
	char line[100];
	while(fgets(line, 100, file)) {
		int coeff, expo;
		parse(line, &coeff, &expo); //get coeff and expo from file
		int addResult = addPolyTerm(coeff, expo); //add to polynomial
		//if addPolyTerm fails
		if (addResult == - 1) {
			printf("Error occurred adding polynomial term.\n");
			fclose(file);
			return 1;
		}
	}
	//Close file and dispay polynomial if it was successful
	fclose(file);
	displayPolynomial();
	//Evaluate and display the results for -2, -1, 0, 1, 2
	for(int i = 0; i < 5; i++) {
		int x = i - 2;
		int y = evaluatePolynomial(x);
		printf("for x=%d, y=%d\n", x, y);
	}

	return 0;
}
