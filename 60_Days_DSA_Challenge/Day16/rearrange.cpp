/*
Given a sorted array of positive integers, rearrange the array alternately i.e first element should be maximum value, second minimum value, third second max, fourth second min and so on.

Examples:

    Input: arr[] = {1, 2, 3, 4, 5, 6, 7}
    Output: arr[] = {7, 1, 6, 2, 5, 3, 4}

    Input: arr[] = {1, 2, 3, 4, 5, 6}
    Output: arr[] = {6, 1, 5, 2, 4, 3}

Expected time complexity: O(n).
 */
#include <bits/stdc++.h>
using namespace std;

// Prints max at first position, min at second position
// second max at third position, second min at fourth
// position and so on.
void rearrange(int arr[], int n)
{
    // Auxiliary array to hold modified array
    int temp[n];

    // Indexes of smallest and largest elements
    // from remaining array.
    int small = 0, large = n - 1;

    // To indicate whether we need to copy remaining
    // largest or remaining smallest at next position
    int flag = true;

    // Store result in temp[]
    for (int i = 0; i < n; i++)
    {
        if (flag)
            temp[i] = arr[large--];
        else
            temp[i] = arr[small++];

        flag = !flag;
    }

    // Copy temp[] to arr[]
    for (int i = 0; i < n; i++)
        arr[i] = temp[i];
}

// Driver code
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original Array\n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    rearrange(arr, n);

    cout << "\nModified Array\n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}
