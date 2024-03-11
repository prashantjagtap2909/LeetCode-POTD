class Solution {
public:
    string customSortString(string order, string s) {
        string res = "";
        unordered_map<int, int>mp;
        for(auto &it : s){
            mp[it]++;
        }
        for(auto &it : order){
            if(mp.find(it) != mp.end()){
                res.append(mp[it] , it);
                mp.erase(it);
            }

        }
        for(auto &it : mp){
            res.append(it.second, it.first);
        }
        return res;
    }
};
