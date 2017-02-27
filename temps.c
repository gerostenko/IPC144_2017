// temps.c
//temperature checker

#include<stdio.h>

int main(void)
{

	//define the variables needed;
	int i, NUMS, days;
	int totalHigh = 0;
	int totalLow = 0;
	int highTemp[10];
	int lowTemp[10];
	double average;


	printf("---=== IPC Temperature Analyzer V2.0 ===---\n");
	printf("\n");

	//Input the amount of days the temperature to be checked;
	printf("Please enter the number of days, between 3 and 10, inclusive: ");
	scanf("%d", &NUMS);
	printf("\n");

	//defining the error message for the incorrect amount of days;
	while (NUMS < 3 || NUMS > 10)
	{
		printf("Invalid entry, please enter a number between 3 and 10, inclusive: ");
		scanf("%d", &NUMS);
		printf("\n");
	}

	//High/Low temps input for NUMS days;
	for (i = 0; i < NUMS; i++)
	{
		printf("Day %d - High: ", i + 1);
		scanf("%d", &highTemp[i]);

		printf("Day %d - Low: ", i + 1);
		scanf("%d", &lowTemp[i]);

	// check the conditions, give an error if met any of them and ask for input again;
	while (highTemp[i] > 40 || highTemp[i] < -40 || lowTemp[i] > 40 || lowTemp[i] < -40 || highTemp[i] < lowTemp[i])
	{
		printf("Incorrect values, temperatures must be in the range -40 to 40, high must be greater than low.\n");
			printf("\n");
			printf("Day %d - High: ", i + 1);
			scanf("%d", &highTemp[i]);
			
			printf("Day %d - Low: ", i + 1);
			scanf("%d", &lowTemp[i]);
		}

	}

	//print the table's header;
	printf("\n");
	printf("Day  Hi  Low\n");
	printf("\n");

	//print the table's content;
	for (i = 0; i < NUMS; i++) 
	{
		printf("%d    %d    %d\n",i+1, highTemp[i], lowTemp[i]);
	}

	//input the amount of days for mean calculation;
	printf("\n");
	printf("Enter a number between 1 and %d to see the average temperature for the entered number of days, enter a negative number to exit: ", NUMS);
	scanf("%d", &days);

	//check the conditions, give an error if met any of them and ask for input again;
	while (days == 0 || days > NUMS)
	{
		printf("\n");
		printf("Invalid entry, please enter a number between 1 and %d, inclusive: ", NUMS);
		scanf("%d", &days);
	}

	//take the proper days input
	while (days <= NUMS && days > 0)
	{
		//create a loop for counting the average;
		for (i = 0; i < days; i++)
		{
			totalHigh += highTemp[i];
			totalLow += lowTemp[i];	
			average = (double)(totalHigh + totalLow) / (days * 2); //mean calculation
		}

		printf("\n");
		printf("The average temperature up to day %d is: %.2lf\n", days, average); //mean output
		printf("\n");
		printf("Enter a number between 1 and %d to see the average temperature for the entered number of days, enter a negative number to exit: ", NUMS);
		scanf("%d", &days); //continue with the days input;
		totalHigh = 0; totalLow = 0; average = 0; //to avoid the accumulation null the variables;
	}
	//break the program;
	if (days == -1)
		printf("\n");
		printf("Goodbye!\n");

	return 0;
}
