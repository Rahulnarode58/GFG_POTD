// <<<<<<<<<<<<<<<<<< Top k numbers in a stream <<<<<<<<<<<<<<<<<<
// POTD Date 19-01-2024
// Coding_with_rahul

/*Given N numbers in an array, your task is to keep at most the top K numbers with respect to their frequency.

In other words, you have to iterate over the array, and after each index, determine the top K most frequent numbers until that iteration and store them in an array in decreasing order of frequency. An array will be formed for each iteration and stored in an array of arrays. If the total number of distinct elements is less than K, then keep all the distinct numbers in the array. If two numbers have equal frequency, place the smaller number first in the array.

Example 1:

Input:
N=5, K=4
arr[] = {5, 2, 1, 3, 2} 
Output: 
5 
2 5 
1 2 5 
1 2 3 5 
2 1 3 5 
Explanation:
Firstly there was 5 whose frequency
is max till now. So resulting sequence is {5}.
Then came 2, which is smaller than 5 but
their frequencies are same so resulting sequence is {2, 5}.
Then came 1, which is the smallest among all the
numbers arrived, so resulting sequence is {1, 2, 5}.
Then came 3 , so resulting sequence is {1, 2, 3, 5}
Then again 2, which has the highest
frequency among all numbers, 
so resulting sequence {2, 1, 3, 5}.*/

class Solution {
  public:
    vector<vector<int>> kTop(vector<int>& arr, int N, int K) {
        vector<int> top(K + 1,0);
        vector<vector<int>> ans;
        unordered_map<int, int> mp;
        for (int i = 0; i < N; i++) {
            mp[arr[i]]++;
            top[K] = arr[i];
            auto it = find(top.begin(), top.end() - 1, arr[i]);
            int index = it - top.begin() - 1;
            for (int j = index ; j >= 0; --j) {
                if (mp[top[j]] < mp[top[j + 1]])
                    swap(top[j], top[j + 1]);
                else if ((mp[top[j]] == mp[top[j + 1]]) && (top[j] > top[j+1]))
                    swap(top[j], top[j + 1]);
                else
                    break;
            }
            vector<int>temp;
            for (int i = 0; i < K && top[i] != 0; ++i)
                temp.push_back(top[i]);
            ans.push_back(temp);
        }
        return ans;
    }
};