class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> count(n);
        for(auto ed : edges)
            count[ed[1]] += 1;
        int cnt = 0, ans;
        for(int i = 0; i < n; i++){
            if(count[i] == 0){
                ans = i;
                cnt += 1;
            }
            if(cnt == 2) return -1;
        }
        return ans;
    }
};
