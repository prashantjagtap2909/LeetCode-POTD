class Solution {
public:

    int solve(int index, vector<int>&nums, int target , int n){
        if(index == n){
            if(target == 0) return 1;
            return 0;
        }
        return {solve(index + 1 , nums, target - nums[index], n)  + 
            solve(index + 1, nums, target+nums[index] , n)};
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        return solve(0 , nums , target, nums.size());
    }
};
