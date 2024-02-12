
// <<<<<<<<<<<<<<<<<< Recursive sequence <<<<<<<<<<<<<<<<<<
// POTD Date 12-02-2024
// Coding_with_rahul
// Level : easy
// Company :  MAQ Software

/*A function F is defined as follows F(n)= (1) +(2*3) + (4*5*6) ... upto n terms (look at the examples for better clarity). Given an integer n, determine the F(n).

Note: As the answer can be very large, return the answer modulo 109+7.

Example 1:

Input: n = 5
Output: 365527
Explanation:
F(5) = 1 + 2*3 + 4*5*6 + 7*8*9*10 + 11*12*13*14*15 = 365527.*/

class Solution
{
public:
    int mod = 1e9 + 7;

    long long f(int term, int start, int n)
    {
        if (term > n)
        {
            return 0;
        }

        long long int ans = 1;
        for (int i = 0; i < term; i++)
        {
            ans = ans * start;
            ans = ans % mod;
            start++;
        }

        ans = ans + f(term + 1, start, n);
        ans = ans % mod;

        return ans;
    }

    long long sequence(int n)
    {
        // code here
        long long ans = f(1, 1, n);

        return ans;
    }
};
