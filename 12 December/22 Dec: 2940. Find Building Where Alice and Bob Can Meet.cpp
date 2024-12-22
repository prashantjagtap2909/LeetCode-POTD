class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights,
                                        vector<vector<int>>& queries) {

        vector<int> ans((int)queries.size(), -1);
        vector<pair<int, int>> mp;
        int n = heights.size();
        vector<pair<int, int>> ref;

        for (int i = 0; i < queries.size(); i++) {
            int mini = min(queries[i][0], queries[i][1]);
            int maxi = max(queries[i][0], queries[i][1]);
            if (mini == maxi || heights[mini] < heights[maxi]) {
                ans[i] = maxi;
            } else {
                ref.push_back({maxi, i});
            }
        }
        sort(ref.begin(), ref.end(), greater<>());
        int j = n - 1;
        for (auto it : ref) {
            int mini = min(queries[it.second][0], queries[it.second][1]);
            int maxi = max(queries[it.second][0], queries[it.second][1]);
            for (; j > maxi; j--) {
                while (mp.size() && heights[mp.back().second] < heights[j])
                    mp.pop_back();
                mp.emplace_back(heights[j], j);
            }
            auto idx = upper_bound(mp.rbegin(), mp.rend(),
                                   make_pair(heights[mini], n));
            ans[it.second] = (idx == mp.rend()) ? -1 : idx->second;
        }
        return ans;
    }
};
