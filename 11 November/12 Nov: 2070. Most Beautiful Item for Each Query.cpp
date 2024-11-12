class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        int n = items.size(), m = queries.size();
        vector<pair<int,int>> vp;
        for(int j=0; j<m; j++){
            vp.push_back({queries[j], j});
        }
        sort(vp.begin(), vp.end());
        sort(items.begin(), items.end());

        int maxi = 0, i = 0;
        vector<int> ans(m);
        for(auto it: vp){
            int price = it.first, ind = it.second;
            while(i<n && items[i][0] <= price){
                maxi = max(maxi, items[i][1]);
                i++;
            }
            ans[ind] = maxi;
        }
        return ans;
    }
};
