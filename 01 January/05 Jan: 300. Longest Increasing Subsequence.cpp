class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int cnt = 0;
        vector<int>v(nums.size(),0);
        for(int x : nums){
            int i = 0 , j = cnt;
            while( i != j){
                int mid = (i+j)/2;
                if(v[mid] < x){
                    i = mid + 1;
                }else{
                    j = mid;
                }
            }
            v[i] = x;
            if(i == cnt){
                ++cnt;
            }
        }
        return cnt;
    }
};
