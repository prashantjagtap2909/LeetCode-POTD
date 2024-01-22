class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n =nums.size();
        unordered_map<int,int>mp;
        for(int i =1;i<=n;i++)mp[i]++;

        for(auto a :nums)mp[a]--;
        int duplicate  = 0,missing=0;

        for(auto a :mp){
            if(a.second == -1)duplicate = a.first;
            if(a.second == 1)missing = a.first;
        }

        return {duplicate,missing};
    }
};
