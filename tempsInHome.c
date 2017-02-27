// In-tome task
//temps.c

#include <stdio.h>
#define NUMS 4 

int main(void)
{

	int i, highTemp, lowTemp, totalHighTemp, totalLowTemp, highestTemp, lowestTemp, dayH, dayL;
	double averageTemp;
	totalHighTemp = 0;
	totalLowTemp = 0;
	highestTemp = -41;
	lowestTemp = 41;
	

	printf("---=== IPC Temperature Analyzer ===---\n");

	//High/Low temps inout for NUMS days
	for (i = 0; i < NUMS; i++)
	{
		printf("Enter the high value for day %d: ", i + 1);
		scanf("%d", &highTemp);
		printf("\n");

		printf("Enter the low value for day %d: ", i + 1);
		scanf("%d", &lowTemp);
		printf("\n");

		// check the conditions, give an error if met any of them and ask for input again;
		while (highTemp > 40 || highTemp < -40 || lowTemp > 40 || lowTemp < -40 || highTemp < lowTemp)
		{
			printf("Incorrect values, temperatures must be in the range -40 to 40, high must be greater than low.\n");

			printf("Enter the high value for day %d: ", i + 1);
			scanf("%d", &highTemp);
			printf("\n");

			printf("Enter the low value for day %d: ", i + 1);
			scanf("%d", &lowTemp);
			printf("\n");
		}


		totalHighTemp += highTemp; //total of High Tempteratures
		totalLowTemp += lowTemp;// Total of Low Temperatures

		if (highTemp > highestTemp)
		{
			highestTemp = highTemp;
			dayH = i + 1;
		}
		if (lowTemp < lowestTemp)
		{
			lowestTemp = lowTemp;
				dayL = i + 1;
		}
			
	}

		averageTemp = (double)(totalHighTemp + totalLowTemp) / (2 * NUMS); //Average we count
		printf("The average (mean) temperature was: %.2lf\n", averageTemp);//Average we print
		printf("The highest temperature was %d, on day %d\n", highestTemp, dayH);
		printf("The lowest temperature was %d, on day %d\n", lowestTemp, dayL);


	return 0;
}

