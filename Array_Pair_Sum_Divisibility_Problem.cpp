// >>>>>>>>>>>>>>      New Year Resolution      <<<<<<<<<<<<<<<
// POTD Date 01-01-2024 
// Coding_with_rahul

/*Given an array of integers nums and a number k, write a function that returns true if given array can be divided into pairs such that sum of every pair is divisible by k.

Example 1 :

Input : 
nums = [9, 5, 7, 3]
k = 6
Output: 
True
Explanation: 
{(9, 3), (5, 7)} is a 
possible solution. 9 + 3 = 12 is divisible
by 6 and 7 + 5 = 12 is also divisible by 6.*/



class Solution {
  public:
    bool canPair(vector<int> nums, int k) {
        
// code here 
unordered_map<int,int>mp;
        for(auto it:nums){
            mp[it%k]++;
        }
        for(auto it:mp){
            if(it.first==0 || it.first*2==k){
                if(it.second % 2==1){
                    return false;
                }
            }
            else{
                if(it.second != mp[k-it.first]){
                    return false;
                }
            }
        }
        return true;
    }
};