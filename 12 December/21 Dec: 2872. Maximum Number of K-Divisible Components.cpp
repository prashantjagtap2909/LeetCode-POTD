class Solution {
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& vals, int k) {
        vector<vector<int>> graph(n);
        vector<int> degree(n);
        if (n < 2) return 1;
        for (auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
            degree[edge[0]]++;
            degree[edge[1]]++;
        }

        vector<long long> nodeVal(vals.begin(), vals.end());
        queue<int> leafQ;
        for (int i = 0; i < n; i++) 
            if (degree[i] == 1) leafQ.push(i);

        int compCnt = 0;
        while (!leafQ.empty()) {
            int curr = leafQ.front();
            leafQ.pop();
            degree[curr]--;
            long long carry = 0;
            if (nodeVal[curr] % k == 0) compCnt++;
            else carry = nodeVal[curr];
            for (int nbr : graph[curr]) {
                if (degree[nbr] == 0) continue;
                degree[nbr]--;
                nodeVal[nbr] += carry;
                if (degree[nbr] == 1) leafQ.push(nbr);
            }
        }
        return compCnt;
    }
};
