/*
   Given an array, right rotate it by k elements.

After K=3 rotation

Examples:
Input: arr[] = {1, 2, 3, 4, 5,
                6, 7, 8, 9, 10}
          k = 3
Output: 8 9 10 1 2 3 4 5 6 7

Input: arr[] = {121, 232, 33, 43 ,5}
           k = 2
Output: 43 5 121 232 33

Note : In the below solution, k is assumed to be smaller than or equal to n. We can easily modify the solutions to handle larger k values by doing k = k % n
Algorithm:


rotate(arr[], d, n)
  reverse(arr[], 0, n-1) ;
  reverse(arr[], 0, d-1);
  reverse(arr[], d, n-1);

*/
// C++ program for right rotation of
// an array (Reversal Algorithm)
#include <bits/stdc++.h>

/*Function to reverse arr[]
from index start to end*/
void reverseArray(int arr[], int start,
                  int end)
{
    while (start < end)
    {
        std::swap(arr[start], arr[end]);
        start++;
        end--;
    }
}

/* Function to right rotate arr[]
of size n by d */
void rightRotate(int arr[], int d, int n)
{
    // if in case d>n,this will give segmantation fault.
    d = d % n;
    reverseArray(arr, 0, n - 1);
    reverseArray(arr, 0, d - 1);
    reverseArray(arr, d, n - 1);
}

/* function to print an array */
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        std::cout << arr[i] << " ";
}

// driver code
int main()
{
    int arr[] = {1, 2, 3, 4, 5,
                 6, 7, 8, 9, 10};

    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;

    rightRotate(arr, k, n);
    printArray(arr, n);

    return 0;
}
