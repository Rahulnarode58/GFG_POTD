# <<<<<<<<<<<<<<<<<< Find all Critical Connections in the Graph <<<<<<<<<<<<<<<<<<
# POTD Date 14-02-2024
# Coding_with_rahul
# Level : Hard
# Company :  Amazon
# Code Written in Python
'''
A critical connection refers to an edge that, upon removal, will make it impossible for certain nodes to reach each other through any path. You are given an undirected connected graph with v vertices and e edges and each vertex distinct and ranges from 0 to v-1, and you have to find all critical connections in the graph. It is ensured that there is at least one such edge present.

Note: The answers may be presented in various potential orders. Each edge should be displayed in sorted order. For instance, if there's an edge between node 1 and node 2, it should be stored as (1,2) rather than (2,1). Additionally, it is expected that you store the edges in sorted order.

Example 1:

Input:
0
1
2

Output:
0 1
0 2
Explanation: 
On removing edge (0, 1), you will not be able to
reach node 0 and 2 from node 1. Also, on removing
edge (0, 2), you will not be able to reach node 0
and 1 from node 2.
'''

class Solution:
    def __init__(self):
        self.ans = []
        self.time = 0

    def dfs(self, u, tin, lowest, parent, adj):
        tin[u] = lowest[u] = self.time
        self.time += 1
        
        for v in adj[u]:
            if tin[v] == -1:
                parent[v] = u
                self.dfs(v, tin, lowest, parent, adj)
                
                if lowest[v] > tin[u]:
                    self.ans.append([v, u])
                else:
                    lowest[u] = min(lowest[u], lowest[v])
            elif tin[v] > -1 and v != parent[u]:
                lowest[u] = min(lowest[u], lowest[v])

    def criticalConnections(self, v, adj):
        tin = [-1] * v
        lowest = [-1] * v
        parent = [-1] * v
        
        for i in range(v):
            if tin[i] == -1:
                self.dfs(i, tin, lowest, parent, adj)
        
        for i in range(len(self.ans)):
            self.ans[i].sort()
        self.ans.sort()
        
        return self.ans
    