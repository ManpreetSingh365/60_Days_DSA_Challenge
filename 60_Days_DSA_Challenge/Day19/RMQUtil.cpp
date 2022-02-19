// C++ Program to find the occurrence
// of the most frequent number within
// a given range
#include <bits/stdc++.h>
using namespace std;

// A utility function to get the middle index
// from corner indexes.
int getMid(int s, int e) { return s + (e - s) / 2; }

/* A recursive function to get the maximum value in
    a given range of array indexes. The following
    are parameters for this function.

    st --> Pointer to segment tree
    index --> Index of current node in the segment
            tree. Initially 0 is passed as root is
            always at index 0
    ss & se --> Starting and ending indexes of the
                segment represented by current node,
                i.e., st[index]
    qs & qe --> Starting and ending indexes of query
                range */
int RMQUtil(int *st, int ss, int se, int qs, int qe,
            int index)
{
    // If segment of this node is a part of given range,
    // then return the min of the segment
    if (qs <= ss && qe >= se)
        return st[index];

    // If segment of this node is outside the
    // given range
    if (se < qs || ss > qe)
        return 0;

    // If a part of this segment overlaps
    // with the given range
    int mid = getMid(ss, se);
    return max(RMQUtil(st, ss, mid, qs, qe, 2 * index + 1),
               RMQUtil(st, mid + 1, se, qs, qe, 2 * index + 2));
}

// Return minimum of elements in range from
// index qs (query start) to
// qe (query end). It mainly uses RMQUtil()
int RMQ(int *st, int n, int qs, int qe)
{
    // Check for erroneous input values
    if (qs < 0 || qe > n - 1 || qs > qe)
    {
        printf("Invalid Input");
        return -1;
    }

    return RMQUtil(st, 0, n - 1, qs, qe, 0);
}

// A recursive function that constructs Segment Tree
// for array[ss..se]. si is index of current node in
// segment tree st
int constructSTUtil(int arr[], int ss, int se, int *st,
                    int si)
{
    // If there is one element in array, store it in
    // current node of segment tree and return
    if (ss == se)
    {
        st[si] = arr[ss];
        return arr[ss];
    }

    // If there are more than one elements, then
    // recur for left and right subtrees and store
    // the minimum of two values in this node
    int mid = getMid(ss, se);
    st[si] = max(constructSTUtil(arr, ss, mid, st, si * 2 + 1),
                 constructSTUtil(arr, mid + 1, se, st, si * 2 + 2));
    return st[si];
}

/* Function to construct segment tree from given
array. This function allocates memory for segment
tree and calls constructSTUtil() to fill the
allocated memory */
int *constructST(int arr[], int n)
{
    // Allocate memory for segment tree

    // Height of segment tree
    int x = (int)(ceil(log2(n)));

    // Maximum size of segment tree
    int max_size = 2 * (int)pow(2, x) - 1;

    int *st = new int[max_size];

    // Fill the allocated memory st
    constructSTUtil(arr, 0, n - 1, st, 0);

    // Return the constructed segment tree
    return st;
}

int maximumOccurrence(int arr[], int n, int qs, int qe)
{
    // Declaring a frequency array
    int freq_arr[n + 1];

    // Counting frequencies of all array elements.
    unordered_map<int, int> cnt;
    for (int i = 0; i < n; i++)
        cnt[arr[i]]++;

    // Creating frequency array by replacing the
    // number in array to the number of times it
    // has appeared in the array
    for (int i = 0; i < n; i++)
        freq_arr[i] = cnt[arr[i]];

    // Build segment tree from this frequency array
    int *st = constructST(freq_arr, n);

    int maxOcc; // to store the answer

    // Case 1: numbers are same at the starting
    // and ending index of the query
    if (arr[qs] == arr[qe])
        maxOcc = (qe - qs + 1);

    // Case 2: numbers are different
    else
    {
        int leftmost_same = 0, righmost_same = 0;

        // Partial Overlap Case of a number with some
        // occurrences lying inside the leftmost
        // part of the range and some just before the
        // range starts
        while (qs > 0 && qs <= qe && arr[qs] == arr[qs - 1])
        {
            qs++;
            leftmost_same++;
        }

        // Partial Overlap Case of a number with some
        // occurrences lying inside the rightmost part of
        // the range and some just after the range ends
        while (qe >= qs && qe < n - 1 && arr[qe] == arr[qe + 1])
        {
            qe--;
            righmost_same++;
        }
        // Taking maximum of all three
        maxOcc = max({leftmost_same, righmost_same,
                      RMQ(st, n, qs, qe)});
    }
    return maxOcc;
}

// Driver Code
int main()
{
    int arr[] = {-5, -5, 2, 2, 2, 2, 3, 7, 7, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    int qs = 0; // Starting index of query range
    int qe = 9; // Ending index of query range

    // Print occurrence of most frequent number
    // within given range
    cout << "Maximum Occurrence in range is = "
         << maximumOccurrence(arr, n, qs, qe) << endl;

    qs = 4; // Starting index of query range
    qe = 9; // Ending index of query range

    // Print occurrence of most frequent number
    // within given range
    cout << "Maximum Occurrence in range is = "
         << maximumOccurrence(arr, n, qs, qe) << endl;

    return 0;
}
