class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        map<int, int>mp1 , mp2;
        for(auto &it : target){
            mp1[it]++;
        }
        for(auto &it : arr){
            mp2[it]++;
        }
        auto it2 = mp2.begin();
        for(auto &it1 : mp1){
            if(it1.first != it2->first || it1.second != it2->second) return false;
            it2++;
        }
        return true;
    }
};
