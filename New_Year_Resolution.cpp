// >>>>>>>>>>>>>>      New Year Resolution      <<<<<<<<<<<<<<<
// POTD Date 31-12-2023 
// Coding_with_rahul

/*As the clock struck midnight on New Year's Eve, Geek bid farewell to the wasted moments of 2023, realizing the untapped potential of GFG's Problem of the Day.

His 2024 resolution: Solve POTD every day.

Eager to earn coins for GFG Merchandise, Geek faces new rules:

Earning Coin: Geek can accumulate coins[i] by solving the POTD on the ith day, where 1 <= coins[i] <= 2024 and the sum of coins <= 2024.
Merchandise Eligibility: To purchase merchandise, the coins earned must be divisible by 20 or 24, or precisely equal to 2024.
Geek's resolutions often fades over time. Realistically, he can only commit to active participation for N (where N ≤ 366) days. Given the value of N and number of coins associated with each POTD, can Geek strategically solve some (or all) POTDs to become eligible for redeeming merchandise?

Example 1:

Input:
N = 8
coins = [5, 8, 9, 10, 14, 2, 3, 5]

Output: 1

Explanation:
Geek can fulfill the criteria in many ways.
One such way is to solve POTD on 4th and 5th day.
Another way is to solve POTD on 1st, 4th and 8th day.*/

class Solution {
    
    public:
    int isPossible(int N , int coins[]) 
    {
        int sum=0;
        for(int i=0;i<N;i++){
            sum+=coins[i];
        }
        
        if(sum%20==0 || sum%24==0 || sum==2024){
            return 1;
        }
        
        vector<vector<int>>dp(N+1, vector<int>(sum+1,0));
        for(int i=0;i<=N;i++){
            dp[i][0]=1;
        }
        
        for(int i=1;i<=N;i++){
            for(int x=0;x<=sum;x++){
                dp[i][x]=dp[i-1][x];
                if(x>=coins[i-1]){
                    dp[i][x]= dp[i][x] || dp[i-1][x-coins[i-1]];
                }
                
                if(x>=1 && dp[i][x] && (x%20==0 || x%24==0 || x==2024)){
                    return 1;
                }
            }
            
        }
        
        return 0;
    }
    
};
