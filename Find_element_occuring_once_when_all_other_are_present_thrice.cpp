// >>>>>>>>>>>>>>      Find element occuring once when all other are present thrice      <<<<<<<<<<<<<<<
// POTD Date 04-01-2024 
// Coding_with_rahul

/*Given an array of integers arr[] of length N, every element appears thrice except for one which occurs once.
Find that element which occurs once.

Example 1:

Input:
N = 4
arr[] = {1, 10, 1, 1}
Output:
10
Explanation:
10 occurs once in the array while the other
element 1 occurs thrice.*/


#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int singleElement(int arr[] ,int N) {
        vector<int> f(32, 0);
        
        for(int i = 0; i < N; i++){
            for(int j = 0; j < 32; j++){
                f[j] += (arr[i] >> j) & 1;
            }
        }
        
        int ans = 0;
        
        for(int i = 0; i < 32; i++)
            ans += (f[i] % 3) << i;
            
        return ans;
    }
};
