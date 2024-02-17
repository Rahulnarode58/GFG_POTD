// <<<<<<<<<<<<<<<<<< Does array represent Heap <<<<<<<<<<<<<<<<<<
// POTD Date 17-02-2024
// Coding_with_rahul
// Level : easy
// Company :  Cisco

/*Given an array arr of size n, the task is to check if the given array can be a level order representation of a Max Heap.

Example 1:

Input:
n = 6
arr[] = {90, 15, 10, 7, 12, 2}
Output:
1
Explanation:
The given array represents below tree
       90
     /    \
   15      10
  /  \     /
7    12  2
The tree follows max-heap property as every
node is greater than all of its descendants.*/

class Solution
{
public:
    bool isMaxHeap(int arr[], int n)
    {
        queue<int> q;
        q.push(arr[0]);

        for (int i = 1; i < n; i++)
        {
            int big = q.front();
            q.pop();

            if (arr[i] > big)
                return 0;

            q.push(arr[i]);

            if (i + 1 < n)
            {
                if (arr[i + 1] > big)
                    return 0;

                q.push(arr[i + 1]);
                ++i;
            }
        }

        return 1;
    }
};