/*
   You are given an array arr[] of N integers including 0. The task is to find the smallest positive number missing from the array.

Example 1:

Input:
N = 5
arr[] = {1,2,3,4,5}
Output: 6
Explanation: Smallest positive missing
number is 6.
Example 2:

Input:
N = 5
arr[] = {0,-10,1,3,-20}
Output: 2
Explanation: Smallest positive missing
number is 2.

*/

int missingNumber(int arr[], int n)
{
    sort(arr, arr + n);

    int sum = 1;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == sum)
        {
            sum++;
        }
    }
    return sum;
}