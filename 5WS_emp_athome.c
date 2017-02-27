/*
Workshop: 5
Section: IPC144
Date: 02/14/2017
*/

#include <stdio.h>
#define SIZE 4



struct employeeStruct {
	int id;          
	int age;		 
	double salary;	
};


int main(void) {

	int option = 0;
	int i = 0;
	int store = 0;
	struct employeeStruct emp[SIZE] = { { 0 } };
	int searchId = 0;
	int storeTheId = 0;

	printf("---=== EMPLOYEE DATA ===---\n\n");


	do {
		
		printf("1. Display Employee Information\n");
		printf("2. Add Employee\n");
		printf("3. Update Employee Salary\n");
		printf("4. Remove Employee\n");
		printf("0. Exit\n\n");
		printf("Please select from the above options: ");


		scanf("%d", &option);
		printf("\n");

		switch (option) {
		case 0:	
			printf("Exiting Employee Data Program. Good Bye!!!\n");
			break;

		case 1:
			printf("EMP ID  EMP AGE EMP SALARY\n");
			printf("======  ======= ==========\n");

			for (i = 0; i < SIZE; i++) {
				if (emp[i].id > 0) {
					printf("%6d%9d%11.2lf", emp[i].id, emp[i].age, emp[i].salary);
					printf("\n");
				}
			}
			printf("\n");

			break;
		case 2:	

			printf("Adding Employee\n");
			printf("===============\n");
			if (store < SIZE) {
				printf("Enter Employee ID: ");
				scanf("%d", &emp[store].id);
				printf("Enter Employee Age: ");
				scanf("%d", &emp[store].age);
				printf("Enter Employee Salary: ");
				scanf("%lf", &emp[store].salary);
				printf("\n");
				store++;

			}
			else {
				printf("ERROR!!! Maximum Number of Employees Reached\n");
				printf("\n");
			}

			break;
		case 3:
			printf("Update Employee Salary\n");
			printf("======================\n");

			do {
				printf("Enter Employee ID: ");
				scanf("%d", &searchId);
				for (i = 0; i < SIZE; i++)
				{
					if (searchId == emp[i].id)
					{
						storeTheId = i;
					}

				}
			} while (storeTheId < 0);

			printf("The current salary is %.2lf\n", emp[storeTheId].salary);
			printf("Enter Employee New Salary: ");
			scanf("%lf", &emp[storeTheId].salary);

			printf("\n");
			break;
		case 4:
			printf("Remove Employee\n");
			printf("===============\n");
			do {
				printf("Enter Employee ID: ");
				scanf("%d", &searchId);
				for (i = 0; i < SIZE; i++)
				{
					if (searchId == emp[i].id)
					{
						storeTheId = i;
					}

				}
			} while (storeTheId < 0);

			printf("Employee %d will be removed\n", emp[storeTheId].id);
			emp[storeTheId].id = 0; emp[storeTheId].age = 0; emp[storeTheId].salary = 0;
			printf("\n");
			store--;
			for (i = storeTheId+1; i < SIZE; i++)
			{

				emp[i - 1].id = emp[i].id;
				emp[i - 1].age = emp[i].age;
				emp[i - 1].salary = emp[i].salary;
			}
			emp[SIZE-1].id = 0; emp[SIZE-1].age = 0; emp[SIZE-1].salary = 0;

			break;
		default:
			printf("ERROR: Incorrect Option: Try Again\n\n");
		}

	} while (option != 0);


	return 0;
}
