class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        int sz=original.size();
        if (sz!=m*n) return {};
        vector<vector<int>> ans(m);
        for(int i=0; i<m; i++){
            ans[i].assign(original.begin()+i*n, original.begin()+(i+1)*n);
        }
        return ans;
    }
};
