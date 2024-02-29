// <<<<<<<<<<<<<<<<<< Sum of bit differences <<<<<<<<<<<<<<<<<<
// POTD Date 29-02-2024
// Coding_with_rahul
// Level : Medum
// Company : Google
// Topic : Arrays , Bit , Magic , Data Structures

/*Given an array integers arr[], containing n elements, find the sum of bit differences between all pairs of element in the array. Bit difference of a pair (x, y) is the count of different bits at the same positions in binary representations of x and y.
For example, bit difference for 2 and 7 is 2. Binary representation of 2 is 010 and 7 is 111 respectively and the first and last bits differ between the two numbers.

Note: (x, y) and (y, x) are considered two separate pairs.

Example 1:

Input:
n = 2
arr[] = {1, 2}
Output: 4
Explanation: All possible pairs of an array are (1, 1), (1, 2), (2, 1), (2, 2).
Sum of bit differences = 0 + 2 + 2 + 0 = 4*/

class Solution
{
public:
    long long sumBitDifferences(int arr[], int n)
    {
        // code here
        long long ans = 0;
        for (int i = 0; i < 32; i++)
        {
            int count = 0;
            for (int j = 0; j < n; j++)
            {
                if (arr[j] & (1 << i))
                {
                    count++;
                }
            }
            ans += 2LL * (long long)count * (long long)(n - count);
        }
        return ans;
    }
};
