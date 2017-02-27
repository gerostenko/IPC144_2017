/*
== Vehicle Rentals ==
Date	: 14-02-2017
Workshop: #6 in-Lab
*/

#include <stdio.h>

#define distRate1  0.69			// Rate per Kilometer from 0km to 100km (inclusive)
#define distRate2  0.49			// Rate per Kilometer above 100km 

// Structure Declaration for Vehicle Rentals
struct Rental
{
	int id;						// ID of the Rental Vehicle
	double baseDay;				// Daily Base Price 
	double earnings;			// Total earnings from this rental
	double taxes;
};

/* prototype functions addPositive Here*/

double addPositive(double amount, double newAmount)
{
	/* Implement Function addPositive Here*/
	if (newAmount > 0) {
		amount += newAmount;
	}
	else
		printf("newAmount is negative!");

	return amount;
}

double taxCalc(double price, double rate)
{
	double taxes;
	taxes = price*(rate / 100);

	return taxes;
}

double subtractPositive(double amount, double newAmount)
{
	if (newAmount > 0) {
		amount -= newAmount;
	}
	else
		printf("newAmount is negative!");

	return amount;

}

/* main program */
int main()
{
	const int noVehicles = 3;			// Number of Vehicles
	int option;							// Variable to store the option selected
	int flag;							// Flag to support vehicle ID find
	int tempID;							// To hold user input for vehicle ID
	int i = 0;							// Variable for "for-loop" counters

	// Initialize the struct Vehicle Rental
	struct Rental vRent[] = { { 123, 9.95, 0 },{ 124, 19.95, 0 },{125, 29.95, 0} };

	double taxRate = 14;				// Tax rate is 14%
	double discount = 5;    			// Discount amount for rentals (in CAD)

	/*Declare Your Variables Here*/
	int days, distance;
	double basePrice, costForDistance, charge, gift;
	char discountChoice;

	printf("***** Rental Vehicle Management App *****\n\n");

	do
	{
		// Display the option list
		printf("1.) Rental Status\n");
		printf("2.) Apply Charges\n");
		printf("3.) Apply Taxes to All Rentals\n");
		printf("4.) Apply Gift Card\n");
		printf("0.) Log out\n\n");
		printf("Please enter an option to continue: ");

		scanf("%d", &option);

		switch (option)
		{
		case 0: // Exit the program
			break;

		case 1: // Rental Vehicle Status

			printf("\n-- Rental Vehicle Status --\n\n");
			printf("ID#      Earnings\n");
			printf("-------- ----------\n");
			for (i = 0; i < noVehicles; i++)
			{
				printf("%8d %10.2lf\n", vRent[i].id, vRent[i].earnings);
			}
			printf("\n");
			// Use "%8d %10.2lf" formatting to display ID and Earnings for each rental
			// using a loop construct

			break;

		case 2: // Calculate Rental Charges

			flag = -1;
			printf("\n-- Rental Charges --\n\n");
			printf("Enter vehicle ID: ");
			scanf("%d", &tempID);


			// Finding the correct vehicle index
			for (i = 0; i < noVehicles && flag == -1; i++) {
				if (tempID == vRent[i].id) {
					flag = i;
				}
			}

			if (flag != -1) {

				// Capture #days for the rental from user input
				printf("Enter Rental Period (in Days): ");
				scanf("%d", &days);


				// Calculate the base price (baseDay * Days)
				basePrice = days * vRent[flag].baseDay;

				// Calculate cost for Kilometers driven using "distRate1 & 2 above"
				printf("Enter kilometers driven: ");
				scanf("%d", &distance);
				if (distance <= 100)
				{
					costForDistance = distance*distRate1;
				}
				else if (distance >= 100)
				{
					costForDistance = ((distance - 100)*distRate2) + 69;
				}

				// Add base Price and cost for kilometer driven in to a new variable
				charge = basePrice + costForDistance;

				/* Call addPositive function with current earnings for the rental and
				charge(calculated above) as arguments and assign the returned
				result back to earnings
				*/
				vRent[flag].earnings = addPositive(vRent[flag].earnings, charge);

				printf("Apply Discount: ");
				scanf(" %c", &discountChoice);

				switch (discountChoice) {
				case 'Y':
				case 'y':

					vRent[flag].earnings = subtractPositive(vRent[flag].earnings, discount);

					break;

				default:
					discountChoice = 'N';

				}

				// Display Base Charge, cost for km and the Total 
				printf("\nBase   kmCost DiscStatus Total\n");
				printf("====== ====== ========== ======\n");
				// Use "%6.2lf %6.2lf %6.2lf" formatting inside a printf statement
				printf("%6.2lf %6.2lf %10c %6.2lf\n", basePrice, costForDistance, discountChoice, vRent[flag].earnings);
				printf("\n");
			}
			else {
				printf("ERROR: Vehicle ID does not exist.\n\n");
			}

			break;
		case 3: // Apply Taxes to all Earnings

			printf("\n-- Apply Taxes To all Accounts--\n\n");

			printf("ID#      Earnings   Taxes\n");
			printf("-------- ---------- ------\n");

			// Iterate over all Rentals. For each rental, calculate the taxes by calling taxCalc
			for (i = 0; i < noVehicles; i++)
			{
				vRent[i].taxes = taxCalc(vRent[i].earnings, taxRate);
				vRent[i].earnings = addPositive(vRent[i].earnings, vRent[i].taxes);
				printf("%8d %10.2lf %6.2lf\n", vRent[i].id, vRent[i].earnings, vRent[i].taxes);
			}
			printf("\n");
			// by passing current earnings and tax rate
			// Then call addPositive with current earnings and the taxes returned from taxCalc function
			// Then use "%8d %10.2lf %6.2lf" formatting to display ID, Earnings and taxes for each rental





			break;

		case 4: // Apply Gift Card

			flag = -1;
			printf("\n-- Apply Gift Card --\n\n");
			printf("Enter vehicle ID: ");
			scanf("%d", &tempID);


			// Finding the correct vehicle index
			for (i = 0; i < noVehicles && flag == -1; i++) {
				if (tempID == vRent[i].id) {
					flag = i;
				}
			}
			if (flag != -1) {

				// Capture Gift card amount
				printf("Enter Gift Card Amount: ");
				scanf("%lf", &gift);

				/* call function subtractPositive with current earnings for the rental and Gift card
				amount as arguments and assign the returned result back to earnings
				*/
				vRent[flag].earnings = subtractPositive(vRent[flag].earnings, gift);
				printf("Discount Applied\n");

			}
			else {
				printf("ERROR: Vehicle ID does not exist.\n\n");
			}

			printf("\n");

			break;

		default:
			printf("Error: Please enter a valid option to continue\n\n");
			break;
		}


	} while (option != 0);


	return 0;
}
