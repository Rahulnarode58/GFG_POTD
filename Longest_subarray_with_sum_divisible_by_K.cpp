// <<<<<<<<<<<<<<<<<<  Longest subarray with sum divisible by K  <<<<<<<<<<<<<<<<<<
// POTD Date 10-01-2024
// Coding_with_rahul
 /*
Given an array arr containing N integers and a positive integer K, find the length of the longest sub array with sum of the elements divisible by the given value K.

Example 1:

Input:
N = 6, K = 3
arr[] = {2, 7, 6, 1, 4, 5}
Output: 
4
Explanation:
The subarray is {7, 6, 1, 4} with sum 18, which is divisible by 3. 
*/

class Solution{
public:	
	int longSubarrWthSumDivByK(int arr[], int n, int k)
	{
	    // Complete the function
	    unordered_map<int,int>mp;
	    int sum=0, ans=0;
	    int i=0;
	    while(i<n){
	        sum+=arr[i];
	        int rem = ((sum%k)+k)%k;
	        if(rem == 0){
	            ans = i+1;
	        }
	        else{
	            if(mp.find(rem)!=mp.end()){
	                ans =max(ans, i-mp[rem]);
	            }
	            else{
	                mp[rem]=i;
	            }
	        }
	        i++;
	    }
	    return ans;
	}
};
