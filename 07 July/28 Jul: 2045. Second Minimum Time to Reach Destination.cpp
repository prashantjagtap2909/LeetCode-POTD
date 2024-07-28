class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<vector<int>> adj(n);
        for (auto it : edges) {
            adj[it[0] - 1].push_back(it[1] - 1);
            adj[it[1] - 1].push_back(it[0] - 1);
        }
        vector<priority_queue<int>> dist(n);
        for (int i = 0; i < n; i++) {
            dist[i].push(1e8);
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;
        pq.push({0, 0});
        dist[0].pop();
        dist[0].push(0);
        while (!pq.empty()) {
            int dis = pq.top().first;
            int cur = pq.top().second;
            pq.pop();
            int k = dis / change;
            if ((k % 2) == 1) {
                dis += (change - (dis% change));
            }
            for (auto it : adj[cur]) {
                int distance = dis + time;
                if (dist[it].top() == 1e8) {
                    dist[it].pop();
                    dist[it].push(distance);
                    pq.push({distance, it});
                } else if (dist[it].size() < 2 && dist[it].top() != distance) {
                    dist[it].push(distance);
                    pq.push({distance, it});
                } else {
                    if (dist[it].top() > distance) {
                        dist[it].pop();
                        dist[it].push(distance);
                        pq.push({distance, it});
                    }
                }
            }
        }
        return dist[n-1].top();
    }
};
