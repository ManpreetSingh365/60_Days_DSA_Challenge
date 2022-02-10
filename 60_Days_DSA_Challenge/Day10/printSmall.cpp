/*
   You are given an array of n-elements you have to find k smallest elements from the array but they must be in the same order as they are in given array and we are allowed to use only O(1) extra space.
Examples:


Input : arr[] = {4, 2, 6, 1, 5},
            k = 3
Output : 4 2 1
Explanation : 1, 2 and 4 are three smallest
numbers and 4 2 1 is their order in given array

Input : arr[] = {4, 12, 16, 21, 25},
            k = 3
Output : 4 12 16
Explanation : 4, 12 and 16 are 3 smallest numbers
and 4 12 16 is their order in given array

We have discussed efficient solution to find n smallest elements of above problem with using extra space of O(n). To solve it without using any extra space we will use concept of insertion sort.
The idea is to move k minimum elements to beginning in same order. To do this, we start from (k+1)-th element and move till end. For every array element, we replace the largest element of first k elements with the current element if current element is smaller than the largest. To keep the order, we use insertion sort idea.
*/

// CPP for printing smallest k numbers in order
#include <algorithm>
#include <iostream>
using namespace std;

// Function to print smallest k numbers
// in arr[0..n-1]
void printSmall(int arr[], int n, int k)
{
    // For each arr[i] find whether
    // it is a part of n-smallest
    // with insertion sort concept
    for (int i = k; i < n; ++i)
    {
        // find largest from first k-elements
        int max_var = arr[k - 1];
        int pos = k - 1;
        for (int j = k - 2; j >= 0; j--)
        {
            if (arr[j] > max_var)
            {
                max_var = arr[j];
                pos = j;
            }
        }

        // if largest is greater than arr[i]
        // shift all element one place left
        if (max_var > arr[i])
        {
            int j = pos;
            while (j < k - 1)
            {
                arr[j] = arr[j + 1];
                j++;
            }
            // make arr[k-1] = arr[i]
            arr[k - 1] = arr[i];
        }
    }
    // print result
    for (int i = 0; i < k; i++)
        cout << arr[i] << " ";
}

// Driver program
int main()
{
    int arr[] = {1, 5, 8, 9, 6, 7, 3, 4, 2, 0};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 5;
    printSmall(arr, n, k);
    return 0;
}
