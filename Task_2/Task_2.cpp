// Task 2. The user enters the company's profit for the year (12 months).
// The user then enters a range (for example, 316 - to search between the third and sixth months).
// It is necessary to determine the month in which the profit was maximum and the month in which the profit was minimum,
// taking into account the selected range.

#include <iostream>
#include "windows.h"
using namespace std;

int main()
{
	const int m = 12;
	int months[m];	// Arrray 12 months
	

	//for (int i = 0; i < m; i++)	// User data in 
	//{
	//	int out = i + 1;
	//	cout << "\n\n\tMonth " << out << ": ";
	//	cin >> months[i];
	//	system("cls");
	//}

	srand(time(NULL));

	for (int i = 0; i < 12; i++)	// Generate profit
	{
		int ran = rand() % 6 + 1;
		if (ran == 2)	// 1 to 6 for negative profit
		{
			int r = rand() % 500 + 0;
			r = r - r * 2;
			months[i] = r;
		}
		else // Random profit
		{
			months[i] = rand() % 500 + 0;			
		}
	}

	cout << "\n\n\t+|================|+\n\t|| Month | Profit ||\n\t||-------|--------||";	// Table output 

	for (int i = 0; i < m; i++)
	{
		int out = i + 1;
		cout << "\n\t||   " << out << "\t | " << months[i] << "\t  ||";		
	}
	cout << "\n\t+|================|+";														//

/*
+|================|+
|| Month | Profit ||
||-------|--------||
||   1   | 128    ||
||   2   | 77     ||
||   3   | 466    ||
||   4   | -466   ||
||   5   | -260   ||
||   6   | 318    ||
||   7   | 429    ||
||   8   | 42     ||
||   9   | 57     ||
||   10  | 94     ||
||   11  | 369    ||
||   12  | 19     ||
+|================|+
*/
	int range_1 = 0, range_2 = 0;

	cout << "\n\n\tEnter months diapazon";	// User diapazon in
	
	cout << "\n\tFrom: "; cin >> range_1;// Data in

	while ((range_1 < 1) || (range_1 > 12))//	If incorrecr value
	{
		cout << "\n\tError -- Incorrect value\n\tMomth can be (1 -- 12)\n\n\tEnter months diapazon\n\tFrom: "; cin >> range_1;	// Error and new try to input
		
	}

	

	cout << "\n\tTo: "; cin >> range_2;// Data in

	while ((range_2 < 1) || (range_2 > 12))//	If incorrecr value
	{
		cout << "\n\tError -- Incorrect value\n\tMomth can be (1 -- 12)\n\n\tEnter months diapazon\n\tTo: "; cin >> range_2;		// Error and new try to input
	}
	range_1 -= 1;// Necessary for correct display in the table
	range_2 -= 1;

	if (range_1 > range_2)// Replacement of input numbers if the set range is incorrect
	{
		int temp = range_1;
		range_1 = range_2;
		range_2 = temp;
	}

	int max = INT_MIN, min = INT_MAX;
	int max_month = 0, min_month = 0;

	for (int i = range_1; i <= range_2; i++)	// Determining the maximum and minimum values in a given range
	{
		if (max < months[i])
		{
			max = months[i]; // Determining the maximum value
			max_month = i;	 // Determining the month of  maximum value
		}

		if (min > months[i])
		{
			min = months[i]; // Determining the minimum value
			min_month = i;	 // Determining the month of  minimum value
		}
	}

	max_month += 1; // Necessary for correct display in the table
	min_month += 1;

		//system("cls");

	cout << "\n\n\t+|================|+\n\t|| Month | Profit ||\n\t||-------|--------||";	// Table output 

	for (int i = range_1; i <= range_2; i++)
	{
		int out = i + 1;
		cout << "\n\t||   " << out << "\t | " << months[i] << "\t  ||";
	}
	cout << "\n\t+|================|+";

	cout << "\n\n\t+|================================|+\n\t||////////////|  Month  | Profit  ||\n\t||------------|---------|---------||";
	cout << "\n\t||  Maximum   |\t  " << max_month << "\t|  " << max << "\t  ||\n\t||------------|---------|---------||";
	cout << "\n\t||  Minimum   |\t  " << min_month << "\t|  " << min << "\t  ||";
	cout << "\n\t+|================================|+\n\n\n\n";								//

/*
+|================|+
|| Month | Profit ||
||-------|--------||
||   3   | 466    ||
||   4   | -466   ||
||   5   | -260   ||
||   6   | 318    ||
+|================|+

+|================================|+
||////////////|  Month  | Profit  ||
||------------|---------|---------||
||  Maximum   |   3     |  466    ||
||------------|---------|---------||
||  Minimum   |   4     |  -466   ||
+|================================|+
*/
}

