/*

Given an array of numbers, arrange them in a way that yields the largest value. For example, if the given numbers are {54, 546, 548, 60}, the arrangement 6054854654 gives the largest value. And if the given numbers are {1, 34, 3, 98, 9, 76, 45, 4}, then the arrangement 998764543431 gives the largest value.

So how do we go about it? The idea is to use any comparison based sorting algorithm.
In the used sorting algorithm, instead of using the default comparison, write a comparison function myCompare() and use it to sort numbers.

Given two numbers X and Y, how should myCompare() decide which number to put first – we compare two numbers XY (Y appended at the end of X) and YX (X appended at the end of Y). If XY is larger, then X should come before Y in output, else Y should come before. For example, let X and Y be 542 and 60. To compare X and Y, we compare 54260 and 60542. Since 60542 is greater than 54260, we put Y first.

Following is the implementation of the above approach.
To keep the code simple, numbers are considered as strings, the vector is used instead of a normal array.
*/
// Given an array of numbers,
// program to arrange the numbers
// to form the largest number
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// A comparison function which
// is used by sort() in
// printLargest()
int myCompare(string X, string Y)
{
    // first append Y at the end of X
    string XY = X.append(Y);

    // then append X at the end of Y
    string YX = Y.append(X);

    // Now see which of the two
    // formed numbers is greater
    return XY.compare(YX) > 0 ? 1 : 0;
}

// The main function that prints
// the arrangement with the
// largest value. The function
// accepts a vector of strings
void printLargest(vector<string> arr)
{

    // Sort the numbers using
    // library sort function. The
    // function uses our comparison
    // function myCompare() to
    // compare two strings. See
    // http://www.cplusplus.com/reference/
    // algorithm/sort/
    // for details
    sort(arr.begin(), arr.end(), myCompare);

    for (int i = 0; i < arr.size(); i++)
        cout << arr[i];
}

// Driver code
int main()
{
    vector<string> arr;

    // output should be 6054854654
    arr.push_back("54");
    arr.push_back("546");
    arr.push_back("548");
    arr.push_back("60");
    printLargest(arr);

    return 0;
}
