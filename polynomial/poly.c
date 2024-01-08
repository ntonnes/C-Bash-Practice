#include <stdio.h>
#include <stdlib.h>
#include "poly.h"
#include "utils.h"

// Struct for linked list of polynomial terms
struct PolyTerm {
	int coeff;
	int expo;
	struct PolyTerm *next;
};


// Global pointer to the head node
struct PolyTerm *head = NULL;


int addPolyTerm (int coeff, int expo) {
	
	// This block finds cur and prev such that one of the following is true:
	// (1.) coeff == cur->coeff
	// (2.) a new node must be inserted between cur and prev
	struct PolyTerm *cur = head;
	struct PolyTerm *prev = NULL;

	while (cur != NULL && cur->expo < expo) {
		prev = cur;
		cur = cur->next;
	}
	
	// Now, handle the two cases described above:
	// Case (1.)
	if (cur != NULL && cur->expo == expo) {
		cur->coeff += coeff;
		return 0;
	}

	// Case (2.)
	else {
		// Attempt to create a new node; if malloc fails, not enough memory 
		struct PolyTerm *newNode = (struct PolyTerm *)malloc(sizeof(struct PolyTerm));
		if (newNode == NULL) { return -1;};
		
		// Populate newNode
		newNode->coeff = coeff;
		newNode->expo = expo;
		newNode->next = cur;

		// If newNode was inserted after a NULL node, it is the new head
		// Otherwise, update *next of the node we just inserted after
		if (prev == NULL) { head = newNode; }
		else { prev->next = newNode; }

		return 0;
	}		
}


void displayPolynomial () {
	struct PolyTerm *cur = head;
	int first = 1;

	// Iterate through each node
	while (cur != NULL) {
		//Print first term
		if (first == 1) {
			printf("%dx%d", cur->coeff, cur->expo);
			first = 0;
		} else {			
			if (cur->coeff < 0) {
				printf("%dx%d", cur->coeff, cur->expo);
			} else {
				printf("+%dx%d", cur->coeff, cur->expo);
			}
		}

		if (cur->next == NULL) {
			printf("\n");
		}

		cur = cur->next;
	}
}


int evaluatePolynomial (int x) {
	int acc = 0;
	struct PolyTerm *cur = head;

	// Iterate through each node, evaluate, then add the result to the accumulator
	while (cur != NULL) {
		acc += cur->coeff * powi(x, cur->expo);
		cur = cur->next;
	}

	return acc;
}
