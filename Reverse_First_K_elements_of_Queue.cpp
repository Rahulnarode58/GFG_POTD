// <<<<<<<<<<<<<<<<<<  Reverse First K elements of Queue <<<<<<<<<<<<<<<<<<
// POTD Date 12-01-2024
// Coding_with_rahul

/*Given an integer K and a queue of integers, we need to reverse the order of the first K elements of the queue, leaving the other elements in the same relative order.

Only following standard operations are allowed on queue.

enqueue(x) : Add an item x to rear of queue
dequeue() : Remove an item from front of queue
size() : Returns number of elements in queue.
front() : Finds front item.
Note: The above operations represent the general processings. In-built functions of the respective languages can be used to solve the problem.

Example 1:

Input:
5 3
1 2 3 4 5
Output: 
3 2 1 4 5
Explanation: 
After reversing the given
input from the 3rd position the resultant
output will be 3 2 1 4 5.*/


class Solution
{
    public:
    
    // Function to reverse first k elements of a queue.
    queue<int> modifyQueue(queue<int> q, int k) {
        // add code here.
        int n = q.size();
        
        stack<int>st;
        for(int i=0;i<=k-1;i++){
            st.push(q.front());
            q.pop();
        }
        for(int i=0;i<k;i++){
            q.push(st.top());
            st.pop();
        }
        for(int i=0;i<n-k;i++){
            q.push(q.front());
            q.pop();
        }
        
        return q;
    }
};
