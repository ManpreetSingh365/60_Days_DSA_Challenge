/*
   Approach with efficient zero shiftings:

Although the above solution is efficient, we can further optimise it in shifting zero algorithms by reducing the number of operations.

In the above shifting algorithms, we scan some elements twice when we set the count index to last index element to zero.

Efficient Zero Shifting Algorithms:

int lastSeenPositiveIndex = 0;
for( index = 0; index < n; index++)
{
    if(array[index] != 0)
    {
        swap(array[index], array[lastSeenPositiveIndex]);
        lastSeenPositiveIndex++;
    }
}

*/
// Utility Function For Swapping Two Element Of An Array
void swap(int& a, int& b) { a = b + a - (b = a); }

// shift all zero to left side of an array
void shiftAllZeroToLeft(int array[], int n)
{
	// Maintain last index with positive value
	int lastSeenNonZero = 0;

	for (index = 0; index < n; index++)
	{
		// If Element is non-zero
		if (array[index] != 0)
		{
			// swap current index, with lastSeen non-zero
			swap(array[index], array[lastSeenNonZero]);

			// next element will be last seen non-zero
			lastSeenNonZero++;
		}
	}
}

