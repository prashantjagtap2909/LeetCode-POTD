class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        const long long INF = LLONG_MAX;
        int n = 26;
        vector<vector<long long>> dist(n, vector<long long>(n, INF));

        for (int i = 0; i < n; ++i) {
            dist[i][i] = 0;
        }

        for (int i = 0; i < original.size(); ++i) {
            dist[original[i] - 'a'][changed[i] - 'a'] = min(dist[original[i] - 'a'][changed[i] - 'a'], (long long)cost[i]);
        }

        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (dist[i][k] < INF && dist[k][j] < INF) {
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }

        long long totalCost = 0;
        for (int i = 0; i < source.size(); ++i) {
            if (source[i] != target[i]) {
                int srcChar = source[i] - 'a';
                int tgtChar = target[i] - 'a';
                if (dist[srcChar][tgtChar] == INF) {
                    return -1; 
                }
                totalCost += dist[srcChar][tgtChar];
            }
        }
        return totalCost < INF ? totalCost : -1;
    }
};
