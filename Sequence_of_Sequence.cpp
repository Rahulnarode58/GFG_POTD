// <<<<<<<<<<<<<<<<<< Sequence of Sequence <<<<<<<<<<<<<<<<<<
// POTD Date 16-01-2024
// Coding_with_rahul

/* Given two integers m and n, try making a special sequence of numbers seq of length n such that

seqi+1 >= 2*seqi 
seqi > 0
seqi <= m
Your task is to determine total number of such special sequences possible.

Example 1:

Input: 
m = 10
n = 4
Output: 
4
Explaination: 
There should be n elements and 
value of last element should be at-most m. 
The sequences are {1, 2, 4, 8}, {1, 2, 4, 9}, 
{1, 2, 4, 10}, {1, 2, 5, 10}.
*/

class Solution{
public:
    int solve(int i, int n, int m, vector<vector<int>>&dp){
        if(n==1){
            return 1;
        }
        if(i>=m){
            return 0;
        }
        if(dp[i][n]!=-1) return dp[i][n];
        
        int ans=0;
        for(int x=2*i;x<=m;x++){
            ans+=solve(x, n-1, m, dp);
        }
        return dp[i][n] = ans;
    }
    
    int numberSequence(int m, int n){
        // code here
        vector<vector<int>>dp(m+1, vector<int>(n+1,-1));
        int ans=0;
        for(int i=1;i<=m;i++){
            ans+=solve(i, n, m, dp);
        }
        return ans;
    }
};