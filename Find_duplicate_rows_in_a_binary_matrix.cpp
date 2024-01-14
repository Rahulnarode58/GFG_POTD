// <<<<<<<<<<<<<<<<<< Find duplicate rows in a binary matrix  <<<<<<<<<<<<<<<<<<
// POTD Date 14-01-2024
// Coding_with_rahul

/*Given a boolean matrix of size RxC where each cell contains either 0 or 1, find the row numbers (0-based) of row which already exists or are repeated.

Example 1:

Input:
R = 2, C = 2
matrix[][] = {{1, 0},
            {1, 0}}
Output: 
1
Explanation:
Row 1 is duplicate of Row 0.*/

class Solution
{   
    public:
    vector<int> repeatedRows(vector<vector<int>> &matrix, int M, int N) 
    { 
        // Your code here
        vector<int>ans;
        set<vector<int>>s;
        for(int i=0;i<M;i++){
            if(s.find(matrix[i])!=s.end()){
                ans.push_back(i);
            }
            else{
                s.insert(matrix[i]);
            }
        }
        
        return ans;
      
    } 
};
