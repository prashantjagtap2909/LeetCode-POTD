class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        long long res  = 0 , cnt = 1;
        vector<int>v(n , 0);
        for(auto it: roads){
            v[it[0]]++;
            v[it[1]]++;
        }
        sort(v.begin() , v.end());
        for(auto i : v){
            res += i * (cnt++);
        }
        return res;
    }
};
