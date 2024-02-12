class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate , cnt = 0 , n = nums.size();

        for(int i = 0 ; i < n ; i++){
            if(cnt == 0){
                cnt=1;
                candidate = nums[i];
            }else{
                if(candidate == nums[i]) cnt++;
                else cnt--;
            }
        }
        return candidate;
    }
};
