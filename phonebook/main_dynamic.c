#include "a4phonebook_dynamic.c"

// fill a char array with up to n characters from stdin
// clears input buffer if necessary
// returns the char array
char *getStr(char *arr, int n) {
        if (fgets(arr, n, stdin) != NULL) {
		char *newline = strchr(arr,'\n');
                if (newline != NULL) {
			*newline = '\0';
		} else {
			char c;
                        while ((c = getchar()) != '\n' && c != EOF) {}
		}
	}
        return arr;
};

// if the char array contains a single integer, return it
// in any other case return -1
int toInt(const char *str) {
	if (str == NULL || *str == '\0' || *str == ' ') {
		return -1; 
	}
	char *end;
	long num = strtol(str,&end,10);   
	if (*end == '\0') {
		return (int)num; 
	}
	return -1;

};

// combines the previous two functions
int getInt(char *arr, int max) {
	return toInt(getStr(arr,max)); 
};

void mkRecord() {
	char name[50], birth[12], phone[15];
	printf("Enter name: ");
	getStr(name,sizeof(name));
	printf("Enter birth date: ");
	getStr(birth,sizeof(birth));
	printf("Enter phone number: ");
	getStr(phone,sizeof(phone));
	addRecord(name, birth, phone);
};

int menu() {
	printf("Phonebook Menu: (1)Add, (2)Find, (3)List, (4)Quit > ");
	char input[3];
	return getInt(input, sizeof(input));
};

int main() {
	char input[100];
	pbSize = 0;
	printf("Enter phonebook size: ");
        pbSize = getInt(input, sizeof(input));
	if (dynamicSize(pbSize)) {return 1; }

	loadCSV("phonebook.csv");
	while (1) {
		int choice = menu();
		// (1) Add
		if (choice == 1) {
			if (phonebook_length == pbSize) {
				puts("Error: phonebook is full");
				continue;
			} else {mkRecord(); }
		}
		// (2) Find
		else if (choice == 2) {
			char name[50];
			puts("Enter name: ");
        		findRecord( getStr(name, sizeof(name)) );
		}
		// (3) List
		else if (choice == 3) {
			if (listRecords()) {
				puts("Error: phonebook is empty");
			}
		}
		// (4) Quit
		else if (choice == 4) {break; }
		// Any other input
		else {puts("Invalid menu selection"); }
	};
	// Only reachable via (4) Quit
	saveCSV("phonebook.csv");
	free(phonebook);
	puts("End of phonebook program");
	return 0;
};

