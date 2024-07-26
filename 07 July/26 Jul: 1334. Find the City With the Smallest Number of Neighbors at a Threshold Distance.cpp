class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> distance(n, vector<int>(n, 1000000000)); // Initialize distance matrix with infinity

        for (int i = 0; i < n; ++i) {
            distance[i][i] = 0; // Distance to itself is 0
        }

        for (auto& edge : edges) {
            distance[edge[0]][edge[1]] = edge[2];
            distance[edge[1]][edge[0]] = edge[2];
        }

        // Floyd-Warshall algorithm to find all-pairs shortest path
        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    distance[i][j] = min(distance[i][j], distance[i][k] + distance[k][j]);
                }
            }
        }

        int ans = -1;
        int mini = INT_MAX;
        for (int i = 0; i < n; ++i) {
            int count = 0;
            for (int j = 0; j < n; ++j) {
                if (i != j && distance[i][j] <= distanceThreshold) {
                    ++count;
                }
            }
            if (count <= mini) {
                mini = count;
                ans = i;
            }
        }

        return ans;
    }
};
