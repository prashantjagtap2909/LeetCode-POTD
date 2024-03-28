class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size(), i = 0 , j = 0 , res = 0;
        unordered_map<int , int>mp;
        while(j < n){
            mp[nums[j]]++;
            if(mp[nums[j]] > k){
                while(i < j && mp[nums[j]] > k){
                    if(mp[nums[i]] == 1) mp.erase(nums[i]);
                    else mp[nums[i]]--; i++;  
                }
            }
            res = max(res , j-i+1);
            j++;
        }
        return res;
    }
};
