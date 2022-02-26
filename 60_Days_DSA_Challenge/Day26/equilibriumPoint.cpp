/*
Given an array A of n positive numbers. The task is to find the first Equilibium Point in the array.
Equilibrium Point in an array is a position such that the sum of elements before it is equal to the sum of elements after it.

Example 1:

Input:
n = 5
A[] = {1,3,5,2,2}
Output: 3
Explanation: For second test case
equilibrium point is at position 3
as elements before it (1+3) =
elements after it (2+2).


Example 2:

Input:
n = 1
A[] = {1}
Output: 1
Explanation:
Since its the only element hence
its the only equilibrium point.


Your Task:
The task is to complete the function equilibriumPoint() which takes the array and n as input parameters and returns the point of equilibrium. Return -1 if no such point exists.

Expected Time Complexity: O(n)
Expected Auxiliary Space: O(1)

Constraints:
1 <= n <= 106
1 <= A[i] <= 108
 */

// { Driver Code Starts
#include <iostream>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to find equilibrium point in the array.
    // a: input array
    // n: size of array

    int equilibriumPoint(long long a[], int n)
    {

        // Your code here
        if (n == 1)
        {
            return 1;
        }

        int sumL = 0;
        int sumR = 0;

        for (int i = 0; i < n; i++)
        {
            sumR = sumR + a[i];
        }
        sumR = sumR - a[0];

        for (int i = 1; i < n - 1; i++)
        {
            sumL = sumL + a[i - 1];
            sumR = sumR - a[i];

            if (sumL == sumR)
            {
                return i + 1;
            }
        }
        return -1;
    }
};

// { Driver Code Starts.

int main()
{

    long long t;

    // taking testcases
    cin >> t;

    while (t--)
    {
        long long n;

        // taking input n
        cin >> n;
        long long a[n];

        // adding elements to the array
        for (long long i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        Solution ob;

        // calling equilibriumPoint() function
        cout << ob.equilibriumPoint(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends