// <<<<<<<<<<<<<<<<<< Split Array Largest Sum  <<<<<<<<<<<<<<<<<<
// POTD Date 07-01-2024
// Coding_with_rahul

/*Given an array arr[] of N elements and a number K., split the given array into K subarrays such that the maximum subarray sum achievable out of K subarrays formed is minimum possible. Find that possible subarray sum.

Example 1:

Input:
N = 4, K = 3
arr[] = {1, 2, 3, 4}
Output: 4
Explanation:
Optimal Split is {1, 2}, {3}, {4}.
Maximum sum of all subarrays is 4,
which is minimum possible for 3 splits.*/


class Solution {
  public:
    bool check(int arr[], int N, int K, int mid){
        int sum=0;
        int count=0;
        
        for(int i=0;i<N;i++){
            if(arr[i]>mid){
                return false;
            }
            
            sum+=arr[i];
            if(sum > mid){
                count++;
                sum=arr[i];
            }
        }
        count++;
        
        if(count > K){
            return false;
        }
        return true;
    }
  
    int splitArray(int arr[] ,int N, int K) {
        // code here
        int mini=0, maxi=0;
        for(int i=0 ;i<N; i++){
            mini = max(mini, arr[i]);
            maxi +=arr[i];
        }
        
        int ans=maxi;
        while(mini <= maxi){
            int mid = (mini+maxi)/2;
            if(check(arr, N, K, mid)){
                ans=mid;
                maxi=mid-1;
            }
            else{
                mini=mid+1;
            }
        }
        
        return ans;
    }
};
