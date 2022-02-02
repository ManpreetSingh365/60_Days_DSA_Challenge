/*
Given two integers a and b. Your task is to print the even number first and odd number next in individual lines.
Note: Must print end of the line at the end.

Example 1:

Input: a = 2, b = 3Output: 23
Example 2:

Input: a = 5, b = 2Output:25

*/

void evenOdd(int a, int b)
{

    cout << ((a & 1) ? b : a) << endl; // if a is ODD, Print b else Print a
    cout << ((a & 1) ? a : b) << endl;
}