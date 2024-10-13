class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<pair<int, int>> vec;
        for (int i = 0; i < nums.size(); i++)
            for (int j = 0; j < nums[i].size(); j++)
                vec.push_back({nums[i][j], i});

        sort(vec.begin(), vec.end());

        vector<int> check(nums.size());
        int cnt = 0, j = 0, ans = 1e9, start = -1, end = -1;
        for (int i = 0; i < vec.size(); i++){
            check[vec[i].second]++;
            if (check[vec[i].second] == 1)
                cnt++;
            while (cnt == nums.size()){
                int range = vec[i].first - vec[j].first;
                if (range < ans){
                    ans = range;
                    start = vec[j].first;
                    end = vec[i].first;
                }
                if (--check[vec[j].second] == 0)
                    cnt--;
                j++;
            }
        }
        return {start, end};
    }
};
