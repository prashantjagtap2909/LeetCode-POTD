class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        for(int i = 0 ; i < nums.size(); i++){
            nums[i] %= 2;
    }
    vector<int>prefix(nums.size()+1);
    prefix[0] = 1;
    int sum = 0 , res = 0;
    for(int i = 0 ; i < nums.size() ; i++){
        sum += nums[i];
        res += (sum >= k) ? prefix[sum - k] : 0;
        prefix[sum]++;
    }
    return res;
    }
    
};
