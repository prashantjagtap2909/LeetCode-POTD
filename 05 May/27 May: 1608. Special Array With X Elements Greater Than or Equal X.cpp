class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int i = 1 ; i <= n ; i++){
            if(nums[n - i] >= i && (n - i == 0 || nums[n - i - 1] < i)){
                return i;
            }
            
        }
        return -1;
        
    }
};
