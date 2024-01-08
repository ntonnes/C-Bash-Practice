// 1.1 The phonebook C file
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 1.2 The phone record structure
struct PHONE_RECORD {
	char name[50];
	char birthdate[12];
	char phone[15];
};

// 1.3 The phonebook array
struct PHONE_RECORD phonebook[10];
int phonebook_length = 0;

// to remove clutter
char header[] = "---- NAME ----   ---- BIRTH DATE ----   ---- PHONE ----";

// 1.4 Adding a phone record to the array
int addRecord(char name[], char birth[], char phone[]) {
	int end = phonebook_length;
	if (end == 10) { return 1; };
	strcpy(phonebook[end].name, name);
	strcpy(phonebook[end].birthdate, birth);
	strcpy(phonebook[end].phone, phone);
	phonebook_length++;
	return 0;
};

// my helper to print one formatted record at index i
void printRecord(int i) {
	printf("%-*s", 14, phonebook[i].name);
        printf("   %-*s   ", 20, phonebook[i].birthdate);
        printf("%-*s\n", 10, phonebook[i].phone);
};

// 1.5 Listing all the phone records in the phonebook
int listRecords() {
	if (phonebook_length == 0) { return 1; };
	puts(header);
	for (int i=0; i<phonebook_length; i++) {printRecord(i);};
	return 0;
};

// 1.6 Finding a phone record in the phonebook
int findRecord(char name[]) {
	for (int i=0;i<phonebook_length;i++) {
		if (!(strcmp(phonebook[i].name, name))) {
			puts(header);
			printRecord(i);
			return i;
		};
	};
	puts("Phone record not found");
	return -1;
};

// counts the number of '\n' characters in a file, which corresponds to the number of records
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

// 1.7 Filling the array from a CSV file
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

// 1.8 Saving the array to a CSV file
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

