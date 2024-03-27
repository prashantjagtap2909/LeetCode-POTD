class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        int res = 0;
        for(int i = 0 ; i < n ; i++){
            int st = 1;
            for(int j = i ; j < n ; j++){
                st = st*nums[j];
                if(st >= k) break;

                res++;
            }
        }
        return res;
    }
};
