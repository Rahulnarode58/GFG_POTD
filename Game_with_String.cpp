
// <<<<<<<<<<<<<<<<<< Game with String <<<<<<<<<<<<<<<<<<
// POTD Date 19-02-2024
// Coding_with_rahul
// Level : Medium
// Company :  Amazon
// Topic : Strings ,Heap , Data Structures

/*Given a string s of lowercase alphabets and a number k, the task is to print the minimum value of the string after removal of k characters. The value of a string is defined as the sum of squares of the count of each distinct character present in the string.

Example 1:

Input:
s = abccc, k = 1
Output:
6
Explaination:
We remove c to get the value as 12 + 12 + 22*/

/*Task:
You do not need to read input or print anything. Your task is to complete the function minValue() which takes s and k as input parameters and returns the minimum possible required value.

Expected Time Complexity: O(n+klog(p))  where n is the length of string and p is number of distinct alphabets and k number of alphabets to be removed.
Expected Auxiliary Space: O(n)

Constraints:
0 ≤ k ≤ |string length| ≤ 105*/

class Solution
{
public:
    int minValue(string s, int k)
    {
        // code here
        unordered_map<char, int> mp;
        for (int i = 0; i < s.length(); i++)
        {
            mp[s[i]]++;
        }
        priority_queue<int> pq;
        for (auto it : mp)
        {
            if (it.second != 0)
            {
                pq.push(it.second);
            }
        }
        for (int i = 0; i < k; i++)
        {
            int a = pq.top();
            pq.pop();
            a--;
            if (a > 0)
            {
                pq.push(a);
            }
        }
        int ans = 0;
        while (!pq.empty())
        {
            ans = ans + pq.top() * pq.top();
            pq.pop();
        }
        return ans;
    }
};
