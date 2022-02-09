/*

Given an array of size n where all elements are distinct and in range from 0 to n-1, change contents of arr[] so that arr[i] = j is changed to arr[j] = i.
Examples:


Example 1:
Input: arr[]  = {1, 3, 0, 2};
Output: arr[] = {2, 0, 3, 1};
Explanation for the above output.
Since arr[0] is 1, arr[1] is changed to 0
Since arr[1] is 3, arr[3] is changed to 1
Since arr[2] is 0, arr[0] is changed to 2
Since arr[3] is 2, arr[2] is changed to 3

Example 2:
Input: arr[]  = {2, 0, 1, 4, 5, 3};
Output: arr[] = {1, 2, 0, 5, 3, 4};

Example 3:
Input: arr[]  = {0, 1, 2, 3};
Output: arr[] = {0, 1, 2, 3};

Example 4:
Input: arr[]  = {3, 2, 1, 0};
Output: arr[] = {3, 2, 1, 0};   
*/

#include <bits/stdc++.h>
using namespace std;

// A simple method to rearrange 'arr[0..n-1]' so that 'arr[j]'
// becomes 'i' if 'arr[i]' is 'j'
void rearrangeNaive(int arr[], int n)
{
    // Create an auxiliary array of same size
    int temp[n], i;

    // Store result in temp[]
    for (i = 0; i < n; i++)
        temp[arr[i]] = i;

    // Copy temp back to arr[]
    for (i = 0; i < n; i++)
        arr[i] = temp[i];
}

// A utility function to print contents of arr[0..n-1]
void printArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        cout << ("%d ", arr[i]);
    cout << ("\n");
}

// Driver code
int main()
{
    int arr[] = {1, 3, 0, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << ("Given array is \n");
    printArray(arr, n);

    rearrangeNaive(arr, n);

    cout << ("Modified array is \n");
    printArray(arr, n);
    return 0;
}

// This code is contributed by Code_Mech
