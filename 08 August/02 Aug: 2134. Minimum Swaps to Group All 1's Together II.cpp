class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size(), total = 0;
        for(auto num : nums){
            total += num;
        }
        if(total == 0 || total == n) return 0;
        int curr = 0;
        for(int i = 0; i < total; i++){
            curr += nums[i];
        }
        int maxi = curr;
        for(int i = 0 ; i < n ; i++){
            curr -= nums[i];
            curr += nums[(i + total) % n];
            maxi = max(maxi , curr);
        }
        return total - maxi;
    }
};
