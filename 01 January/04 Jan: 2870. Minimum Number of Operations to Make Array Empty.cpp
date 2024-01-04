class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(auto a : nums){
            mp[a]++;
        }
        int cnt = 0;
        for(auto it : mp){
            int temp = it.second;
            if(temp == 1) return -1;
            cnt += temp/3;
            if(temp % 3) 
                cnt++;
        }
        return cnt;
    }
};
