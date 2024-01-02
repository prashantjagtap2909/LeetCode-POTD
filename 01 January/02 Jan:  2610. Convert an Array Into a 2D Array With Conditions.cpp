class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int , int>mp;
        for(auto &i : nums){
            mp[i]++;
        }
        vector<vector<int>>res;
        while(!mp.empty()){
            vector<int>temp , delt;
            for(auto &[f,s] : mp){
                temp.emplace_back(f);
                s--;
                if(s==0) delt.emplace_back(f);
            }
            res.emplace_back(temp);
            for(auto &i : delt){
                mp.erase(i);
            }
        }
        return res;
    }
};
