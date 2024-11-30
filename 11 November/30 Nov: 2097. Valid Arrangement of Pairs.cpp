class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        unordered_map<int, vector<int>> graph;
        unordered_map<int, int> outdegree, indegree;

        for (auto& pair : pairs) {
            int start = pair[0], end = pair[1];
            graph[start].push_back(end);
            outdegree[start]++;
            indegree[end]++;
        }

        int startNode = pairs[0][0];
        for (auto& [node, _] : graph) {
            if (outdegree[node] > indegree[node]) {
                startNode = node;
                break;
            }
        }

        stack<int> stk;
        deque<int> path;
        stk.push(startNode);

        while (!stk.empty()) {
            int node = stk.top();
            if (!graph[node].empty()) {
                int next = graph[node].back();
                graph[node].pop_back();
                stk.push(next);
            } else {
                path.push_front(node);
                stk.pop();
            }
        }

        vector<vector<int>> result;
        auto it = path.begin();
        int prev = *it++;
        while (it != path.end()) {
            result.push_back({prev, *it});
            prev = *it++;
        }

        return result;
    }
};
