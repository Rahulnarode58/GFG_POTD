// <<<<<<<<<<<<<<<<<< Swapping pairs make sum equal <<<<<<<<<<<<<<<<<<
// POTD Date 05-06-2024
// Coding_with_rahul
// Level : Medum
// Company : Amazon
// Topic : Arrays , Hash , Data Structures

/*Given two arrays of integers a[] and b[] of size n and m, the task is to check if a pair of values (one value from each array) exists such that swapping the elements of the pair will make the sum of two arrays equal.

Example 1:

Input: n = 6, m = 4, a[] = {4, 1, 2, 1, 1, 2}, b[] = (3, 6, 3, 3)
Output: 1
Explanation: Sum of elements in a[] = 11, Sum of elements in b[] = 15, To get same sum from both arrays, we can swap following values: 1 from a[] and 3 from b[]*/

/* CODE */

class Solution
{

public:
    int findSwapValues(int a[], int n, int b[], int m)
    {
        // Your code goes here
        int suma = 0, sumb = 0;
        for (int i = 0; i < n; i++)
            suma += a[i];
        for (int i = 0; i < m; i++)
            sumb += b[i];

        if ((suma - sumb) % 2 != 0)
            return -1;
        int target = (suma - sumb) / 2;
        int i = 0, j = 0;
        sort(a, a + n);
        sort(b, b + m);
        while (i < n && j < m)
        {
            int diff = a[i] - b[j];
            if (diff == target)
                return 1;
            else if (diff < target)
                i++;
            else
                j++;
        }
        return -1;
    }
};
