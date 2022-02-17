
/*
Given an array of N elements and Q queries of the form L R X. For each query, you have to output if the element X exists in the array between the indices L and R(included).

Naive Approach :
The naive method would be to traverse the elements from L to R for each query, linearly searching for X. In the worst case, there can be N elements from L to R, hence the worst case time complexity for each query would be O(N). Therefore, for all the Q queries, the time complexity would turn out to be O(Q*N).
Using Union-Find Method :
This method checks only one element among all the consecutive equal values. If X is not equal to these values, then the algorithm skips all the other the other equal elements and continues traversal with the next different element. This algorithm is evidently useful only when there are consecutive equal elements in large amounts.
Algorithm :


Merge all the consecutive equal elements in one group.

While processing a query, start from R. Let index = R.

Compare a[index] with X. If they are equal, then print “Yes”
and break out of traversing the rest of the range. Else, skip all
the consecutive elements belonging to the group of a[index]. Index
becomes equal to one less than the index of the root of this group.

Continue the above step either till X is found or till
index becomes less than L.

If index becomes less than L, print “No”.
 */
// Program to determine if the element
// exists for different range queries
#include <bits/stdc++.h>
using namespace std;

// Structure to represent a query range
struct Query
{
    int L, R, X;
};

const int maxn = 100;

int root[maxn];

// Find the root of the group containing
// the element at index x
int find(int x)
{
    return x == root[x] ? x : root[x] = find(root[x]);
}

// merge the two groups containing elements
// at indices x and y into one group
int uni(int x, int y)
{
    int p = find(x), q = find(y);
    if (p != q)
    {
        root[p] = root[q];
    }
}

void initialize(int a[], int n, Query q[], int m)
{
    // make n subsets with every
    // element as its root
    for (int i = 0; i < n; i++)
        root[i] = i;

    // consecutive elements equal in value are
    // merged into one single group
    for (int i = 1; i < n; i++)
        if (a[i] == a[i - 1])
            uni(i, i - 1);
}

// Driver code
int main()
{
    int a[] = {1, 1, 5, 4, 5};
    int n = sizeof(a) / sizeof(a[0]);
    Query q[] = {{0, 2, 2}, {1, 4, 1}, {2, 4, 5}};
    int m = sizeof(q) / sizeof(q[0]);
    initialize(a, n, q, m);

    for (int i = 0; i < m; i++)
    {
        int flag = 0;
        int l = q[i].L, r = q[i].R, x = q[i].X;
        int p = r;

        while (p >= l)
        {

            // check if the current element in
            // consideration is equal to x or not
            // if it is equal, then x exists in the range
            if (a[p] == x)
            {
                flag = 1;
                break;
            }
            p = find(p) - 1;
        }

        // Print if x exists or not
        if (flag != 0)
            cout << x << " exists between [" << l
                 << ", " << r << "] " << endl;
        else
            cout << x << " does not exist between ["
                 << l << ", " << r << "] " << endl;
    }
}
