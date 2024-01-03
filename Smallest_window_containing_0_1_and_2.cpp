//>>>>>>>>> Smallest window containing 0, 1 and 2 <<<<<<<<<<<
// POTD Date 03-01-2024 
// Coding_with_rahul

/*Given a string S consisting of the characters 0, 1 and 2. Your task is to find the length of the smallest substring of string S that contains all the three characters 0, 1 and 2. If no such substring exists, then return -1.

Example 1:

Input:
S = 01212
Output:
3
Explanation:
The substring 012 is the smallest substring
that contains the characters 0, 1 and 2.*/

class Solution {
  public:
    int smallestSubstring(string S) {
        // Code here
        int n=S.length();
        int start=0, end=0;
        int zero=0, one=0, two=0;
        
        int ans = INT_MAX;
        while(end<n){
            while( (end < n) && (!zero || !one || !two)){
                if(S[end]=='0') zero++;
                else if(S[end]=='1') one++;
                else two++;
                
                end++;
            }
            if(zero && one && two){
                ans= min(ans, end-start);
            }
            
            while(start<end && zero && one && two){
                ans=min(ans, end-start);
                if(S[start]=='0') zero--;
                else if(S[start]=='1') one--;
                else two--;
                
                start++;
            }
        }
        
        if(ans==INT_MAX) ans=-1;
        
        return ans;
        
    }
};

