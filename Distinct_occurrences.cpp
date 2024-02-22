// <<<<<<<<<<<<<<<<<< Distinct occurrences <<<<<<<<<<<<<<<<<<
// POTD Date 22-02-2024
// Coding_with_rahul
// Level : Medium
// Company :  Amazon , Google
// Topic : Dynamic Programming and Algorithms

/*Given two strings s and t of length n and m respectively. Find the count of distinct occurrences of t in s as a sub-sequence modulo 109 + 7.

Example 1:

Input:
s = "banana" , t = "ban"
Output:
3
Explanation:
There are 3 sub-sequences:[ban], [ba n], [b an].*/

/*Your Task:
You don't need to read input or print anything.Your task is to complete the function subsequenceCount() which takes two strings as argument s and t and returns the count of the sub-sequences modulo 109 + 7.

Expected Time Complexity: O(n*m).
Expected Auxiliary Space: O(n*m).

Constraints:
1 ≤ n,m ≤ 1000*/

class Solution
{
public:
    int mod = 1e9 + 7;
    int solve(string s, string t, int i, int j, vector<vector<int>> &dp)
    {
        if (t.length() == j)
            return 1;
        if (s.length() == i)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];

        if (s[i] == t[j])
        {
            return dp[i][j] = solve(s, t, i + 1, j + 1, dp) % mod + solve(s, t, i + 1, j, dp) % mod;
        }

        else
        {

            return dp[i][j] = solve(s, t, i + 1, j, dp) % mod;
        }
    }

    int subsequenceCount(string s, string t)
    {

        int n = s.length();
        int m = t.length();

        vector<vector<int>> dp(n, vector<int>(m, -1));
        return solve(s, t, 0, 0, dp) % mod;
    }
};
