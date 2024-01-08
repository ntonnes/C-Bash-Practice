#include <stdio.h>
#include <string.h>
#include "utils.h"

void parse(char *str, int *coeff, int *expo) {
	//scan string of two ints into coeff and expo
	sscanf(str, "%d %d", coeff, expo);
}

int powi(int x, int expo) {
	int result = 1;

        // when expo = 0
        if (expo == 0) {
                return 1;
        }

	//when expo > 0
        for (int i=0; i<expo; ++i) {
                result *= x;
        }

	return result;
}
