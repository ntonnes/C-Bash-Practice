#import <stdio.h>

int main(void) {
	
	//initialize char array to hold stdin string and three int vars to hold numbers
	char nums[100];
	int fst, snd, trd; 

	//extract input numbers from stdin into the three int vars
	puts ("Please input three numbers: ");
	fgets (nums, 100, stdin);
	sscanf (nums, "%d %d %d", &fst, &snd, &trd);

	//initialize booleans that identifies whether the three input numbers satisfy the
	//'divisible' and 'increasing' properties
	_Bool div = ((snd%fst)+(trd%fst) == 0);
	_Bool inc = ((fst<=snd) && (snd<=trd));

	//use booleans to determine how process the terminates
	if ( !div && !inc ) { printf("Not divisible & Not increasing\n"); return 3; }
	else if ( div && !inc ) { printf("Divisible & Not increasing\n"); return 2; }
	else if ( !div && inc ) { printf("Not divisible & Increasing\n"); return 1; }
	else { printf("Divisible & Increasing\n"); return 0; }

}
