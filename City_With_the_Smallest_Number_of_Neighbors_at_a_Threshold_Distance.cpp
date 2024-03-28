// <<<<<<<<<<<<<<<<<< Sum of bit differences <<<<<<<<<<<<<<<<<<
// POTD Date 28-03-2024
// Coding_with_rahul
// Level : Medum
// Company : Google
// Topic : Graph ,Shortest Path , BFS ,Disjoint Set ,Data Structures ,Algorithms

/*There are n cities labeled from 0 to n-1 with m edges connecting them. Given the array edges where edges[i] = [fromi , toi ,weighti]  represents a bidirectional and weighted edge between cities fromi and toi, and given the integer distanceThreshold. You need to find out a city with the smallest number of cities that are reachable through some path and whose distance is at most Threshold Distance. If there are multiple such cities, our answer will be the city with the greatest label.

Note: The distance of a path connecting cities i and j is equal to the sum of the edge's weights along that path.

Example 1:

Input:
n = 4, m = 4
edges = [[0, 1, 3],
         [1, 2, 1],
         [1, 3, 4],
         [2, 3, 1]]
distanceThreshold = 4
Output:
3
Explaination:

The neighboring cities at a distanceThreshold = 4 for each city are:
City 0 -> [City 1, City 2]
City 1 -> [City 0, City 2, City 3]
City 2 -> [City 0, City 1, City 3]
City 3 -> [City 1, City 2]
Cities 0 and 3 have 2 neighboring cities at a distanceThreshold = 4, but we have to return city 3 since it has the greatest number.*/

class Solution
{
public:
    int findCity(int n, int m, vector<vector<int>> &edges, int distanceThreshold)
    {

        vector<pair<int, int>> adj[n];

        for (auto it : edges)
        {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));

        int minCity = INT_MAX;
        int ans = -1;

        for (int src = 0; src < n; src++)
        {
            dist[src][src] = 0;
            set<pair<int, int>> st;
            st.insert({0, src});

            while (!st.empty())
            {
                auto it = *(st.begin());
                int wt = it.first;
                int node = it.second;
                st.erase(it);
                for (auto itr : adj[node])
                {
                    int adjNode = itr.first;
                    int eWt = itr.second;
                    if (wt != INT_MAX && wt + eWt < dist[src][adjNode])
                    {
                        dist[src][adjNode] = wt + eWt;
                        st.insert({wt + eWt, adjNode});
                    }
                }
            }

            int count = 0;
            for (int j = 0; j < n; j++)
            {
                if (src != j && dist[src][j] <= distanceThreshold)
                    count++;
            }
            if (count <= minCity)
            {
                minCity = count;
                ans = src;
            }
        }

        return ans;
    }
};
