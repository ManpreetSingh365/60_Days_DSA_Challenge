/*
   Given an array of n elements, create a new array which is a rotation of given array and hamming distance between both the arrays is maximum.
Hamming distance between two arrays or strings of equal length is the number of positions at which the corresponding character(elements) are different.
Note: There can be more than one output for the given input.
Examples:

Input :  1 4 1
Output :  2
Explanation:
Maximum hamming distance = 2.
We get this hamming distance with 4 1 1
or 1 1 4

Input :  N = 4
         2 4 8 0
Output :  4
Explanation:
Maximum hamming distance = 4
We get this hamming distance with 4 8 0 2.
All the places can be occupied by another digit.
Other possible solutions are 8 0 2 4 and 0 2 4 8.

*/

#include <bits/stdc++.h>
using namespace std;

// Return the maximum hamming distance of a rotation
int maxHamming(int arr[], int n)
{
    // arr[] to brr[] two times so that
    // we can traverse through all rotations.
    int brr[2 * n + 1];
    for (int i = 0; i < n; i++)
        brr[i] = arr[i];
    for (int i = 0; i < n; i++)
        brr[n + i] = arr[i];

    // We know hamming distance with 0 rotation
    // would be 0.
    int maxHam = 0;

    // We try other rotations one by one and compute
    // Hamming distance of every rotation
    for (int i = 1; i < n; i++)
    {
        int currHam = 0;
        for (int j = i, k = 0; j < (i + n); j++, k++)
            if (brr[j] != arr[k])
                currHam++;

        // We can never get more than n.
        if (currHam == n)
            return n;

        maxHam = max(maxHam, currHam);
    }

    return maxHam;
}

// driver program
int main()
{
    int arr[] = {2, 4, 6, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << maxHamming(arr, n);
    return 0;
}
