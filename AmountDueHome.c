// Type the number and convert it into loonies, pennies, nickels, whatever.
//Galina Erostenko, ID 124330618

#include<stdio.h>

int main(void)
{
	double GST, amount;
	int quarters, dimes, nickels, pennies, lastLeft;

		printf("Please enter the amount to be paid: $"); 
		scanf("%lf", &amount); //8.73

	GST = amount * 0.13 + 0.005; //1.14
		printf("GST: %.2lf\n", GST); 

	amount += GST;	//9.87
		printf("Balance owing: $%.2lf\n", amount);
		printf("Loonies required: %d, balance owing $%.2lf\n", (int)amount, amount-(int)amount); 

	pennies = (double)(amount - (int)amount + 0.005) * 100; //87

	quarters = pennies / 25; //3
	pennies = pennies % 25; //12
	printf("Quarters required: %d, balance owing $%.2lf\n", quarters, (double)pennies/100);

	dimes = pennies  / 10; //1
	pennies = pennies % 10; //2
	printf("Dimes required: %d, balance owing $%.2lf\n", dimes, (double)pennies/100);

	nickels = pennies / 5; //0
	pennies = pennies % 5; //2
	printf("Nickels required: %d, balance owing $%.2lf\n", nickels, (double)pennies/100);

	pennies = pennies % 5; //2
	lastLeft = pennies % 1; //0
	printf("Pennies required: %d, balance owing $%.2lf\n", pennies, (double)lastLeft/100);
	return 0;
}