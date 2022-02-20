/*

Given an array of size n and multiple values around which we need to left rotate the array. How to quickly find multiple left rotations?
Examples:


Input : arr[] = {1, 3, 5, 7, 9}
        k1 = 1
        k2 = 3
        k3 = 4
        k4 = 6
Output : 3 5 7 9 1
         7 9 1 3 5
         9 1 3 5 7
         3 5 7 9 1

Input : arr[] = {1, 3, 5, 7, 9}
        k1 = 14
Output : 9 1 3 5 7


Left Rotation of array (Simple and Juggling Algorithms).
Block swap algorithm for array rotation
Reversal algorithm for array rotation
The best of above approaches take O(n) time and O(1) extra space.
Efficient Approach:
The above approaches work well when there is a single rotation required. The approaches also modify the original array. To handle multiple queries of array rotation, we use a temp array of size 2n and quickly handle rotations.
Step 1: Copy the entire array two times in temp[0..2n-1] array.
Step 2: Starting position of array after k rotations in temp[] will be k % n. We do k
Step 3: Print temp[] array from k % n to k % n + n.

*/

#include <bits/stdc++.h>
using namespace std;

// Fills temp[] with two copies of arr[]
void preprocess(int arr[], int n, int temp[])
{
    // Store arr[] elements at i and i + n
    for (int i = 0; i < n; i++)
        temp[i] = temp[i + n] = arr[i];
}

// Function to left rotate an array k times
void leftRotate(int arr[], int n, int k, int temp[])
{
    // Starting position of array after k
    // rotations in temp[] will be k % n
    int start = k % n;

    // Print array after k rotations
    for (int i = start; i < start + n; i++)
        cout << temp[i] << " ";

    cout << endl;
}

// Driver program
int main()
{
    int arr[] = {1, 3, 5, 7, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    int temp[2 * n];
    preprocess(arr, n, temp);

    int k = 2;
    leftRotate(arr, n, k, temp);

    k = 3;
    leftRotate(arr, n, k, temp);

    k = 4;
    leftRotate(arr, n, k, temp);

    return 0;
}
