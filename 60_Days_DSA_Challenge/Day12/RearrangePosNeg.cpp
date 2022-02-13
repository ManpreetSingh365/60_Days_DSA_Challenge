/* 
Given an array of positive and negative numbers, arrange them such that all negative integers appear before all the positive integers in the array without using any additional data structure like hash table, arrays, etc. The order of appearance should be maintained.

Examples:  

Input:  [12 11 -13 -5 6 -7 5 -3 -6]
Output: [-13 -5 -7 -3 -6 12 11 6 5]
Approach: Modified Insertion Sort
We can modify insertion sort to solve this problem.
Algorithm –  

Loop from i = 1 to n - 1.
  a) If the current element is positive, do nothing.
  b) If the current element arr[i] is negative, we 
     insert it into sequence arr[0..i-1] such that 
     all positive elements in arr[0..i-1] are shifted 
     one position to their right and arr[i] is inserted
     at index of first positive element.
*/
#include <stdio.h>

// A utility function to print an array of size n
void printArray(int arr[], int n)
{
	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

// Function to Rearrange positive and negative
// numbers in a array
void RearrangePosNeg(int arr[], int n)
{
	int key, j;
	for (int i = 1; i < n; i++) {
		key = arr[i];

		// if current element is positive
		// do nothing
		if (key > 0)
			continue;

		/* if current element is negative,
		shift positive elements of arr[0..i-1],
		to one position to their right */
		j = i - 1;
		while (j >= 0 && arr[j] > 0) {
			arr[j + 1] = arr[j];
			j = j - 1;
		}

		// Put negative element at its right position
		arr[j + 1] = key;
	}
}

/* Driver program to test above functions */
int main()
{
	int arr[] = { -12, 11, -13, -5, 6, -7, 5, -3, -6 };
	int n = sizeof(arr) / sizeof(arr[0]);

	RearrangePosNeg(arr, n);
	printArray(arr, n);

	return 0;
}
