// Task 3. In a one-dimensional array consisting of N real numbers, calculate:
//
// The sum of negative elements;
// Product of elements located between min and max elements;
// Product of elements with even numbers;
// The sum of elements located between the first and last negative elements.


#include <iostream>
#include "windows.h"
using namespace std;

int main()
{
	bool menu = 1;
	srand(time(NULL));
	do
	{
		const int size = 10;	// Array size
		int nums[size];			// Array
		int neg_sum = 0;		// The sum of negative elements
		int max = INT_MIN, min = INT_MAX;
		int max_num = 0, min_num = 0;
		long long prod = 1;		// Product of elements located between min and max elements
		long long prod_2 = 1;	// Product of elements with even numbers
		int neg_first = -1;		// First negative
		int neg_last = -1;		// Last negative
		int sum_bnfl = 0;		// Sum between negativethe first and last elements.


		for (int i = 0; i < size; i++)	// Generate numbers
		{
			int ran = rand() % 4 + 1;
			if (ran == 2)	// 1 to 4 for negative num
			{
				int r = rand() % 20 + 0;
				r = -r;
				nums[i] = r;
			}
			else // Random nums
			{
				nums[i] = rand() % 20 + 0;
			}
		}
		cout << "\n\n\tArray: ";
		for (int i = 0; i < size; i++)	// Array out
		{
			cout << nums[i] << " ";
		}

		for (int i = 0; i < size; i++)

		{
			if (nums[i] < 0)
			{
				neg_sum += nums[i]; // The sum of negative elements
				neg_last = i;
			}

			if (max < nums[i])
			{
				max = nums[i]; // Determining the maximum value
				max_num = i;	 // Determining the month of  maximum value
			}

			if (min > nums[i])
			{
				min = nums[i]; // Determining the minimum value
				min_num = i;	 // Determining the month of  minimum value
			}

			if (i % 2)
			{
				prod_2 *= nums[i]; // Product of elements with even numbers;
			}

		}

		if (min_num > max_num)
		{
			int temp = min_num;
			min_num = max_num;
			max_num = temp;
		}

		for (int i = min_num + 1; i < max_num; i++)	// Product of elements located between min and max elements;
		{
			prod *= nums[i];
		}

		//int a = -1;
		//do
		//{
		//	neg_first = a;
		//	++a;
		//} while (nums[a] > (-1));

		for (int i = 0; nums[i] >= 0; i++)
		{
			neg_first = i;
		}

		neg_first = neg_first + 2;
		for (int i = --neg_first; i < neg_last; i++)// The sum of elements located between the first and last negative elements.
		{
			sum_bnfl += nums[i];
		}

		if (neg_sum == 0)	// IF Not Set
		{
			cout << "\n\n\tNS\t\t<-- The sum of negative elements";
		}
		else // Data out
		{
			cout << "\n\n\t" << neg_sum << "\t\t<-- The sum of negative elements";
		}
		if (prod == 1)	// IF Not Set
		{
			cout << "\n\tNS\t\t<-- Product of elements located between min and max elements";
		}
		else // Data out
		{
			cout << "\n\t" << prod << "\t\t<-- Product of elements located between min and max elements";
		}

		cout << "\n\t" << prod_2 << "\t\t<-- Product of elements with even numbers"; // Data out

		if (((neg_first == neg_last) || (neg_last == (neg_first + 1) || (neg_first == -1) || (neg_last == -1))) || (sum_bnfl == 0))	// IF Not Set
		{
			cout << "\n\tNS\t\t<-- The sum of elements located between the firstand last negative elements";
		}
		else // Data out
		{
			cout << "\n\t" << sum_bnfl << "\t\t<-- The sum of elements located between the firstand last negative elements";
		}
		cout << "\n\n\t0 -- Exit\n\t1 -- Restart\n\t";	cin >> menu;
		/*
		
        Array: -13 14 -17 12 12 18 -11 6 18 -17

        -58             <-- The sum of negative elements
        144             <-- Product of elements located between min and max elements
        -308448         <-- Product of elements with even numbers
        39              <-- The sum of elements located between the firstand last negative elements

        0 -- Exit
        1 -- Restart
		*/

		system("cls");
	} while (menu != 0);
}