/*
   Write a function rotate(ar[], d, n) that rotates arr[] of size n by d elements.

Array

Rotation of the above array by 2 will make array

Algorithm :

Initialize A = arr[0..d-1] and B = arr[d..n-1]
1) Do following until size of A is equal to size of B

  a)  If A is shorter, divide B into Bl and Br such that Br is of same
       length as A. Swap A and Br to change ABlBr into BrBlA. Now A
       is at its final place, so recur on pieces of B.

   b)  If A is longer, divide A into Al and Ar such that Al is of same
       length as B Swap Al and B to change AlArB into BArAl. Now B
       is at its final place, so recur on pieces of A.

2)  Finally when A and B are of equal size, block swap them.


! Time Complexity: O(n)
*/
#include <bits/stdc++.h>
using namespace std;

/*Prototype for utility functions */
void printArray(int arr[], int size);
void swap(int arr[], int fi, int si, int d);

void leftRotate(int arr[], int d, int n)
{
    /* Return If number of elements to be rotated
    is zero or equal to array size */
    if (d == 0 || d == n)
        return;
    /* If number of elements to be rotated is more than array size*/
    if (d > n)
        d = d % n;
    /*If number of elements to be rotated
    is exactly half of array size */
    if (n - d == d)
    {
        swap(arr, 0, n - d, d);
        return;
    }

    /* If A is shorter*/
    if (d < n - d)
    {
        swap(arr, 0, n - d, d);
        leftRotate(arr, d, n - d);
    }
    else /* If B is shorter*/
    {
        swap(arr, 0, d, n - d);
        leftRotate(arr + n - d, 2 * d - n, d); /*This is tricky*/
    }
}

/*UTILITY FUNCTIONS*/
/* function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

/*This function swaps d elements starting at index fi
with d elements starting at index si */
void swap(int arr[], int fi, int si, int d)
{
    int i, temp;
    for (i = 0; i < d; i++)
    {
        temp = arr[fi + i];
        arr[fi + i] = arr[si + i];
        arr[si + i] = temp;
    }
}

// Driver Code
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    leftRotate(arr, 2, 7);
    printArray(arr, 7);
    return 0;
}

// This code is contributed by rathbhupendra
