/*
   Given an array of n elements. Our task is to write a program to rearrange the array such that elements at even positions are greater than all elements before it and elements at odd positions are less than all elements before it.
Examples:


Input : arr[] = {1, 2, 3, 4, 5, 6, 7}
Output : 4 5 3 6 2 7 1

Input : arr[] = {1, 2, 1, 4, 5, 6, 8, 8}
Output : 4 5 2 6 1 8 1 8
The idea to solve this problem is to first create an auxiliary copy of the original array and sort the copied array. Now total number of even position in array with n elements will be floor(n/2) and remaining is the number of odd positions. Now fill the odd and even positions in the original array using the sorted array in the below manner:


Total odd positions will be n – floor(n/2). Start from (n-floor(n/2))th position in the sorted array and copy the element to 1st position of sorted array. Start traversing the sorted array from this position towards left and keep filling the odd positions in the original array towards right.
Start traversing the sorted array starting from (n-floor(n/2)+1)th position towards right and keep filling the original array starting from 2nd position.
*/

#include <bits/stdc++.h>
using namespace std;

// function to rearrange the array
void rearrangeArr(int arr[], int n)
{
    // total even positions
    int evenPos = n / 2;

    // total odd positions
    int oddPos = n - evenPos;

    int tempArr[n];

    // copy original array in an
    // auxiliary array
    for (int i = 0; i < n; i++)
        tempArr[i] = arr[i];

    // sort the auxiliary array
    sort(tempArr, tempArr + n);

    int j = oddPos - 1;

    // fill up odd position in original
    // array
    for (int i = 0; i < n; i += 2)
    {
        arr[i] = tempArr[j];
        j--;
    }

    j = oddPos;

    // fill up even positions in original
    // array
    for (int i = 1; i < n; i += 2)
    {
        arr[i] = tempArr[j];
        j++;
    }

    // display array
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}

// Driver code
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int size = sizeof(arr) / sizeof(arr[0]);
    rearrangeArr(arr, size);
    return 0;
}
