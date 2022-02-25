/*
 Approach 2 (Sorting, Max heap, Map) :
    Instead of brute-forcing through all the possible sum combinations, we should find a way to limit our search space to possible candidate sum combinations.

    Sort both arrays array A and array B.
    Create a max heap i.e priority_queue in C++ to store the sum combinations along with the indices of elements from both arrays A and B which make up the sum. Heap is ordered by the sum.
    Initialize the heap with the maximum possible sum combination i.e (A[N – 1] + B[N – 1] where N is the size of array) and with the indices of elements from both arrays (N – 1, N – 1). The tuple inside max heap will be (A[N-1] + B[N – 1], N – 1, N – 1). Heap is ordered by first value i.e sum of both elements.
    Pop the heap to get the current largest sum and along with the indices of the element that make up the sum. Let the tuple be (sum, i, j).
    Next insert (A[i – 1] + B[j], i – 1, j) and (A[i] + B[j – 1], i, j – 1) into the max heap but make sure that the pair of indices i.e (i – 1, j) and (i, j – 1) are not
    already present in the max heap. To check this we can use set in C++.
    Go back to 4 until K times.
*/

#include <bits/stdc++.h>
using namespace std;

// Function prints k maximum possible combinations
void KMaxCombinations(vector<int> &A,
                      vector<int> &B, int K)
{
    // sort both arrays A and B
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    int N = A.size();

    // Max heap which contains tuple of the format
    // (sum, (i, j)) i and j are the indices
    // of the elements from array A
    // and array B which make up the sum.
    priority_queue<pair<int, pair<int, int>>> pq;

    // my_set is used to store the indices of
    // the pair(i, j) we use my_set to make sure
    // the indices doe not repeat inside max heap.
    set<pair<int, int>> my_set;

    // initialize the heap with the maximum sum
    // combination ie (A[N - 1] + B[N - 1])
    // and also push indices (N - 1, N - 1) along
    // with sum.
    pq.push(make_pair(A[N - 1] + B[N - 1],
                      make_pair(N - 1, N - 1)));

    my_set.insert(make_pair(N - 1, N - 1));

    // iterate upto K
    for (int count = 0; count < K; count++)
    {
        // tuple format (sum, (i, j)).
        pair<int, pair<int, int>> temp = pq.top();
        pq.pop();

        cout << temp.first << endl;

        int i = temp.second.first;
        int j = temp.second.second;

        int sum = A[i - 1] + B[j];

        // insert (A[i - 1] + B[j], (i - 1, j))
        // into max heap.
        pair<int, int> temp1 = make_pair(i - 1, j);

        // insert only if the pair (i - 1, j) is
        // not already present inside the map i.e.
        // no repeating pair should be present inside
        // the heap.
        if (my_set.find(temp1) == my_set.end())
        {
            pq.push(make_pair(sum, temp1));
            my_set.insert(temp1);
        }

        // insert (A[i] + B[j - 1], (i, j - 1))
        // into max heap.
        sum = A[i] + B[j - 1];
        temp1 = make_pair(i, j - 1);

        // insert only if the pair (i, j - 1)
        // is not present inside the heap.
        if (my_set.find(temp1) == my_set.end())
        {
            pq.push(make_pair(sum, temp1));
            my_set.insert(temp1);
        }
    }
}

// Driver Code.
int main()
{
    vector<int> A = {1, 4, 2, 3};
    vector<int> B = {2, 5, 1, 6};
    int K = 4;

    // Function call
    KMaxCombinations(A, B, K);
    return 0;
}
