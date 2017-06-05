

#include <stdio.h>
#define SIZE 3

void decompose(const long long phone, int *code, int *prefix, int *lineNum);
int isValid(long long phone);

void decompose(const long long phone, int *code, int *prefix, int *lineNum)
{
	//4168771829
	long long rest;

	*code = (int)(phone / 10000000);
	rest = phone % 10000000;
	*prefix = (int)(rest / 10000);
	*lineNum = rest % 10000;

}

int isValid(long long phone)
{
	int GTAcode[SIZE] = {416, 647, 905};
	int prefix, code, i, rest, result=0;
	code = (int)(phone / 10000000);
	rest = phone % 10000000;
	prefix = (int)(rest / 10000);

	for (i = 0; i < SIZE; i++)
	{
		if (code == GTAcode[i] && prefix>=100 && prefix <= 999)
			result = 1;
	}

	return result;
}

/* main program */
int main(void) {

	int option = 0, counter = 0, i = 0, result;
	long long phoneNumber[SIZE] = { 0LL };
	long long tempVar;
	int code = 0;
	int prefix = 0;
	int lineNum = 0;

	printf("---=== Phone Numbers ===---\n\n");

	do {
		// Display the Option List
		printf("1. Display Phone List\n");
		printf("2. Add a Number\n");
		printf("0. Exit\n\n");
		printf("Please select from the above options: ");
		scanf("%d", &option);
		printf("\n");

		switch (option) {
		case 0:	// Exit the program
			printf("Exiting Phone Number App. Good Bye!!!\n");
			break;

		case 1: // Display the Phone List
				// @IN-LAB
			printf("Phone Numbers\n");
			printf("==============\n");
			// Display each number in decomposed form

			for (i = 0; i < counter; i++) {

				decompose(phoneNumber[i], &code, &prefix, &lineNum);
				printf("(%3d)-%3d-%04d\n", code, prefix, lineNum);
			}
			printf("\n");
			break;

		case 2:	// Add a Phone Number
				// @IN-LAB
			printf("Add a Number\n");
			printf("============\n");

				scanf("%lld", &tempVar);
				result =  isValid(tempVar);
				if (result == 1)
				{
					if (counter < SIZE) {
						phoneNumber[counter] = tempVar;
						counter++;
						
					}
				}
				else
				{
					printf("ERROR!!! Phone Number is not Valid\n");
				}
			
			printf("\n");
			break;

		default:
			printf("ERROR!!!: Incorrect Option: Try Again\n\n");
			break;
		}

	} while (option != 0);

	return 0;
}

// Program Input/Output
/*

---=== Phone Numbers ===---

1. Display Phone List
2. Add a Number
0. Exit

Please select from the above options: 1

Phone Numbers
==============

1. Display Phone List
2. Add a Number
0. Exit

Please select from the above options: 2

Add a Number
============
4164915050

1. Display Phone List
2. Add a Number
0. Exit

Please select from the above options: 2

Add a Number
============
9052301212

1. Display Phone List
2. Add a Number
0. Exit

Please select from the above options: 2

Add a Number
============
6475551212

1. Display Phone List
2. Add a Number
0. Exit

Please select from the above options: 1

Phone Numbers
==============
(416)-491-5050
(905)-230-1212
(647)-555-1212

1. Display Phone List
2. Add a Number
0. Exit

Please select from the above options: 2

Add a Number
============
ERROR!!! Phone Number List is Full

1. Display Phone List
2. Add a Number
0. Exit

Please select from the above options: 0

Exiting Phone Number App. Good Bye!!!

*/
