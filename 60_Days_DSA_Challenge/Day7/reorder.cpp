/*

Given two integer arrays of same size, “arr[]” and “index[]”, reorder elements in “arr[]” according to given index array. It is not allowed to given array arr’s length.

Example:

Input:  arr[]   = [10, 11, 12];
        index[] = [1, 0, 2];
Output: arr[]   = [11, 10, 12]
        index[] = [0,  1,  2]

Input:  arr[]   = [50, 40, 70, 60, 90]
        index[] = [3,  0,  4,  1,  2]
Output: arr[]   = [40, 60, 90, 50, 70]
        index[] = [0,  1,  2,  3,   4]
        
A Simple Solution is to use an auxiliary array temp[] of same size as given arrays. Traverse the given array and put all elements at their correct place in temp[] using index[]. Finally copy temp[] to arr[] and set all values of index[i] as i.

*/
// C++ program to sort an array according to given
// indexes
#include <iostream>

using namespace std;

// Function to reorder elements of arr[] according
// to index[]
void reorder(int arr[], int index[], int n)
{
    int temp[n];

    // arr[i] should be present at index[i] index
    for (int i = 0; i < n; i++)
        temp[index[i]] = arr[i];

    // Copy temp[] to arr[]
    for (int i = 0; i < n; i++)
    {
        arr[i] = temp[i];
        index[i] = i;
    }
}

// Driver program
int main()
{
    int arr[] = {50, 40, 70, 60, 90};
    int index[] = {3, 0, 4, 1, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    reorder(arr, index, n);

    cout << "Reordered array is: \n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    cout << "\nModified Index array is: \n";
    for (int i = 0; i < n; i++)
        cout << index[i] << " ";
    return 0;
}
