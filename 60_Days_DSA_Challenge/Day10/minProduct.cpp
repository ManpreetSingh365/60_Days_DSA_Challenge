/*
   Given an array of n positive integers. We are required to write a program to print the minimum product of k integers of the given array.
Examples:


Input : 198 76 544 123 154 675
         k = 2
Output : 9348
We get minimum product after multiplying
76 and 123.

Input : 11 8 5 7 5 100
        k = 4
Output : 1400

*/
// CPP program to find minimum product of
// k elements in an array
#include <bits/stdc++.h>
using namespace std;

int minProduct(int arr[], int n, int k)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < n; i++)
        pq.push(arr[i]);

    int count = 0, ans = 1;

    // One by one extract items from max heap
    while (pq.empty() == false && count < k)
    {
        ans = ans * pq.top();
        pq.pop();
        count++;
    }

    return ans;
}

// Driver code
int main()
{
    int arr[] = {198, 76, 544, 123, 154, 675};
    int k = 2;
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Minimum product is "
         << minProduct(arr, n, k);
    return 0;
}
