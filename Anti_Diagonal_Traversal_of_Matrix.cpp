// Problem  >>>>>>   Anti Diagonal Traversal of Matrix     <<<<<<<<<<
// POTD Date 27-12-2023 
// Coding_with_rahul

/*
Give a N*N square matrix, return an array of its anti-diagonals in top-leftmost to bottom-rightmost order. In an element of a anti-diagonal (i, j), surrounding elements will be (i+1, j-1) and (i-1, j+1). Look at the examples for more clarity.

Example 1:

Input:
N = 2
matrix[][] = 1 2
            3 4
Output:
1 2 3 4
Explanation:
List of anti-diagnoals in order is
{1}, {2, 3}, {4}
*/



class Solution {
  public:
    vector<int> antiDiagonalPattern(vector<vector<int>> matrix) {
        vector<int> result;
        int n = matrix.size();
    
        // Traverse the top row
        for (int j = 0; j < n; ++j) {
            int row = 0;
            int col = j;
            
            // Traverse the anti-diagonal
            while (row < n && col >= 0) {
                result.push_back(matrix[row][col]);
                ++row;
                --col;
            }
        }
    
        // Traverse the rightmost column (excluding the first element)
        for (int i = 1; i < n; ++i) {
            int row = i;
            int col = n - 1;
    
            // Traverse the anti-diagonal
            while (row < n && col >= 0) {
                result.push_back(matrix[row][col]);
                ++row;
                --col;
            }

        }
    
        return result;
    }
};