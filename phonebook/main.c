// 1.9 The main file

#include "a4phonebook.c"

// fills a char array with the first n elements of stdin (length of array)
// removes extra characters from the input buffer
// returns the length of the stored string
int getSTDIN(char *field, int n) {
	int len = 0;
	if (fgets(field, n, stdin) != NULL) {
		if (field[strlen(field) - 1] != '\n') {
			char c;				
			while ((c = getchar()) != '\n' && c != EOF) {}			
		}		  
    	field[strcspn(field, "\n")] = '\0';
	len = strlen(field);
	}
	return len;
};

// adds one record to the phonebook using input from stdin
void mkRecord() {
	char name[50], birth[12], phone[15];
	puts("Enter name:");
	getSTDIN(name, sizeof(name));
	puts("Enter birth date:");
	getSTDIN(birth, sizeof(birth));
	puts("Enter phone number:");
	getSTDIN(phone, sizeof(phone));
	addRecord(name, birth, phone);
};

// 1.10 The menu function
int menu() {
	printf("Phonebook Menu: (1)Add, (2)Find, (3)List, (4)Quit > ");
	char input[3];
	int choice;
	if (getSTDIN(input, sizeof(input)) == 1) {
		if (sscanf(input,"%d",&choice) == 1){
			return choice;
		};
	};
	return -1;
};

// 1.11 The main function
int main() {
	loadCSV("phonebook.csv");
	while (1) {
		int choice = menu();
		// (1) Add
		if (choice == 1) {
			if (phonebook_length == 10) {
				puts("Error: phonebook is full");
			}
			else {mkRecord(); }
		}
		// (2) Find
		else if (choice == 2) {
			char name[50];
			puts("Enter name:");
        		getSTDIN(name, sizeof(name));
                	findRecord(name);
		}
		// (3) List
		else if (choice == 3) {
			if (listRecords()) {
				puts("Error: phonebook is empty");
			}
		}
		// (4) Quit
		else if (choice == 4) { break; }
		// Any other input
		else {puts("Invalid menu selection"); }
	};
	// only reachable via (4) Quit
	saveCSV("phonebook.csv");
	puts("End of phonebook program");
	return 0;
};

