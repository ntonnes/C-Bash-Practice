#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct PHONE_RECORD {
	char name[50];
	char birthdate[12];
	char phone[15];
};

struct PHONE_RECORD *phonebook;
int phonebook_length = 0;
char header[] = "---- NAME ----   ---- BIRTH DATE ----   ---- PHONE ----";

//new global to store dynamic size
int pbSize = 0;

int addRecord(char name[], char birth[], char phone[]) {
	int end = phonebook_length;
	if ( end == pbSize) { return 1; };
	strcpy(phonebook[end].name, name);
	strcpy(phonebook[end].birthdate, birth);
	strcpy(phonebook[end].phone, phone);
	phonebook_length++;
	return 0;
};

void printRecord(int i) {
	printf("%-*s", 14, phonebook[i].name);
        printf("   %-*s   ", 20, phonebook[i].birthdate);
        printf("%-*s\n", 10, phonebook[i].phone);
};

int listRecords() {
	if (phonebook_length == 0) { return 1; };
	puts(header);
	for (int i=0; i<phonebook_length; i++) {printRecord(i);};
	return 0;
};

int findRecord(char name[]) {
	for (int i=0; i<phonebook_length; i++) {
		if (!(strcmp(phonebook[i].name, name))) {
			puts(header);
			printRecord(i);
			return i;
		};
	};
	puts("Phone record not found");
	return -1;
};

int lines(char *filename) {
	FILE *f;
	int n = 0;
       	if (!(f = fopen(filename, "r"))) {return -1;}; 
	while(!feof(f)) {
		if (getc(f)=='\n') {n++;};	
	};
	fclose(f);
	return n;
};


// loads contents of a file into the phonebook
// exit 1 if file is empty, does not exist, or only contains header
// exit 0 if successful
int loadCSV(char *filename) {
	if (lines(filename) < 2) {return 1; };
	phonebook_length = 0;
	FILE *f = fopen(filename, "r");
	char record[80], name[50], birth[12], phone[15] = {0};
	fgets(record,79,f);
	while (fgets(record,79,f)) {
		char *field = strtok(record, ",");
		strncpy(name, field, 49);
		field = strtok(NULL, ",");
		strncpy(birth, field, 11);
		field = strtok(NULL, "\n");
		strncpy(phone, field, 14);
		addRecord(name, birth, phone);
	};
	fclose(f);
	return 0;

};

int saveCSV(char *filename) {
	FILE *f;
	if(!(f = fopen(filename, "w"))) {return 1;};
	if (phonebook_length == 0) {return 2;};
	fputs ("name,birthdate,phone\n", f);
	for (int i=0; i<phonebook_length; i++){
		fprintf(f, "%s,%s,%s\n", phonebook[i].name, phonebook[i].birthdate, phonebook[i].phone);
	};
	fclose(f);
	return 0;
};

// 2 Dynamic Memory
int dynamicSize(int num) {
	free(phonebook);
	phonebook = malloc(num * sizeof(struct PHONE_RECORD));
	if (phonebook == NULL) {
		puts ("Not enough space to store phonebook of this size! Program terminated.");
		return 1; 
	} 
	else {return 0; }
};                         
