# <<<<<<<<<<<<<<<<<< Distribute candies in a binary tree <<<<<<<<<<<<<<<<<<
# POTD Date 20-01-2024
# Coding_with_rahul

'''Given a binary tree with N nodes, in which each node value represents number of candies present at that node. In one move, one may choose two adjacent nodes and move only one candy from one node to another (the move may be from parent to child, or from child to parent.) 
The task is to find the number of moves required such that every node has exactly one candy.
Note that the testcases are framed such that it is always possible to achieve a configuration in which every node has exactly one candy, after some moves.

Example 1:

Input :      3
           /   \
          0     0 
Output : 2
Explanation: 
From the root of the tree, we move one 
candy to its left child, and one candy to
its right child.'''

class Solution:
    def solve(self, root):
        if root is None:
            return 0, 0
        left_profit, a1 = self.solve(root.left)
        right_profit, a2 = self.solve(root.right)
        ans = abs(left_profit) + abs(right_profit)
        return root.data + left_profit + right_profit - 1, ans + a1 + a2
    def distributeCandy(self, root):
        _, ans = self.solve(root)
        return ans