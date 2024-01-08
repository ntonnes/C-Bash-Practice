#include <stdio.h> 
#include <stdbool.h>

_Bool compare(int *w1_chars, int *w2_chars) {

	//iterate over the ASCII values; check if both int arrays have the same value at
	//that index, indicating equal presence of that character in each word
	int i;
	for (i=0; i<256; i++) {
		if (w1_chars[i] != w2_chars[i]) {
			return false;
		}
	}
	return true;
}

int main(int argc, char *argv[]) {

	//initialize two integer arrays to hold a count for the number of each ASCII
	//character occurring in each word
	int w1_chars [256] = {0};
	int w2_chars[256] = {0};

	//check if the two words are the same length, otherwise anagram is impossible
	int len1=0, len2=0;
	while (argv[1][len1]!='\0') { len1++; }
	while (argv[2][len2]!='\0') { len2++; }	
	if (len1!=len2) { puts("Not an anagram"); return 1; }	

	//iterate through both words; increment the words' int array at the index that
	//correspond's to the current character's ASCII value
	int i;		
	for (i=0; argv[1][i]!='\0'; i++) {
		w1_chars[argv[1][i]]++;
		w2_chars[argv[2][i]]++;
		}	

	//run 'compare', which only returns true if the words have identical characters
	_Bool anagram = compare(w1_chars, w2_chars);
	
	//execute termination based on the value of anagram
	if (anagram) { puts("Anagram"); return 0; }
	else { puts("Not an anagram"); return 1; }
}

