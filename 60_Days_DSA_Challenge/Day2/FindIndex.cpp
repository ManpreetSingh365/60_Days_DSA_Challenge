/*
   Given an unsorted array Arr[] of N integers and a Key which is present in this array. You need to write a program to find the start index( index where the element is first found from left in the array ) and end index( index where the element is first found from right in the array ).

Example 1:

Input:
N = 6
arr[] = { 1, 2, 3, 4, 5, 5 }
Key = 5
Output:  4 5
Explanation:
5 appears first time at index 4 and
appears last time at index 5.
(0 based indexing)


Example 2:

Input:
N=6
arr[] = { 6, 5, 4, 3, 1, 2 }
Key = 4
Output:  2 2

Your Task:
Since, this is a function problem. You don't need to take any input, as it is already accomplished by the driver code. You just need to complete the function findIndex() that takes array a, integer N and integer key as parameters and returns an array of length 2 in which at first index contains the value of start index and at the second index contains the value of end index. If the key does not exist in the array then return -1 for both start and end index in this case.



*/

vector<int> findIndex(int a[], int n, int key)
{
    vector<int> v;
    int x = -1;

    for (int i = 0; i < n; i++)
    {
        if (key == a[i])
        {
            if (v.empty() == 1)
            {
                v.push_back(i);
                v.push_back(i);
            }
            else
            {
                v.pop_back();
                v.push_back(i);
            }
        }
    }

    if (v.empty() == 1)
    {
        v.push_back(x);
        v.push_back(x);
    }

    return v;
}