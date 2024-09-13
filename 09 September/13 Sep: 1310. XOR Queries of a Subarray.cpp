class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        partial_sum(arr.begin(), arr.end(), arr.begin(), bit_xor<int>());
        int n=queries.size();
        vector<int> ans(n);
        int i=0;
        for(auto& q: queries){
            int q0=q[0], q1=q[1];
            ans[i++]=(q0==0)?arr[q1]:(arr[q1]^arr[q0-1]);
        }
        return ans;
    }
};
