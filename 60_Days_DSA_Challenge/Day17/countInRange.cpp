/*
Given an unsorted array of size n, find no of elements between two elements i and j (both inclusive).
Examples:


Input :  arr = [1 3 3 9 10 4]
         i1 = 1, j1 = 4
         i2 = 9, j2 = 12
Output : 4
         2
The numbers are: 1 3 3 4 for first query
The numbers are: 9 10 for second query
Source: Amazon Interview Experience


A simple approach will be to run a for loop to check if each element is in the given range and maintain their count. Time complexity for running each query will be O(n).

 */
// Simple C++ program to count number of elements
// with values in given range.
#include <bits/stdc++.h>
using namespace std;

// function to count elements within given range
int countInRange(int arr[], int n, int x, int y)
{
    // initialize result
    int count = 0;
    for (int i = 0; i < n; i++)
    {

        // check if element is in range
        if (arr[i] >= x && arr[i] <= y)
            count++;
    }
    return count;
}

// driver function
int main()
{
    int arr[] = {1, 3, 4, 9, 10, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Answer queries
    int i = 1, j = 4;
    cout << countInRange(arr, n, i, j) << endl;

    i = 9, j = 12;
    cout << countInRange(arr, n, i, j) << endl;
    return 0;
}
