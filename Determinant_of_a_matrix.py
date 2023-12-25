# Problem  >>>>>>>>>> Determinant of a Matrix   <<<<<<<<<<
# POTD Date 25-12-2023 
# Coding_with_rahul
'''Given a square matrix of size n*n. The task is to find the determinant of this matrix.

Example 1:

Input:
n = 4
matrix[][] = {{1, 0, 2, -1},
              {3, 0, 0, 5},
              {2, 1, 4, -3},
              {1, 0, 5, 0}}
Output: 30
Explanation:
Determinant of the given matrix is 30.
Example 2:

Input:
n = 3
matrix[][] = {{1, 2, 3},
              {4, 5, 6},
              {7, 10, 9}}
Output: 12
Explanation:
Determinant of the given matrix is 12. '''


class Solution:
    def cofactor(self, matrix, temp, R, C, n):
        i = 0
        j = 0
        for row in range(n):
            for col in range(n):
                if row != R and col != C:
                   temp[i][j] = matrix[row][col]
                   j += 1
                   if j == n - 1:
                      j = 0
                      i += 1
    def determinantOfMatrix(self,matrix,n):
        ans = 0
        if n == 1:
            return matrix[0][0]
        temp = [[0] * n for _ in range(n)]
        sign = 1
        for i in range(n):
            self.cofactor(matrix, temp, 0, i, n)
            ans += sign*matrix[0][i]*self.determinantOfMatrix(temp, n - 1)
            sign *= -1
        return ans