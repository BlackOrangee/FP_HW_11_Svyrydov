// Task 1. In a one-dimensional array filled with random numbers, determine the minimum and maximum elements.
//

#include <iostream>
using namespace std;
int main()
{
	const int size = 10;
	int nums[size];	// Array

	srand(time(NULL));

	for (int i = 0; i < size; i++)	// Generates an array of size 10 with numbers from 0 to 20
	{
		nums[i] = rand() % 20 + 0;
	}

	int min = nums[0];
	int max = nums[0];

	for (int i = 0; i < size; i++)	// Determinate maximum and minimum numbers of array
	{
		if (max < nums[i])	// Max num
		{
			max = nums[i];
		}
		if (min > nums[i])	// Min num
		{
			min = nums[i];
		}
	}

	cout << "Array: ";

	for (int i = 0; i < size; i++)	// Output array
	{
		cout << nums[i] << " ";
	}

	cout << "\nMin: " << min << "\nMax: " << max;	// Output maximum and minimum numbers of array
	
	/*	Array: 13 13 8 17 5 4 6 12 4 2
	*	Min: 2
	*	Max: 17
	*/
}
