class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        vector<vector<int>>v;
        sort(nums.begin() , nums.end());
        for(int i = 0 ; i +2 < nums.size() ; i++){
            if(i % 3 == 0){
                if(nums[i+2] - nums[i] <= k){
                    v.push_back({nums[i], nums[i+1],nums[i+2]});
                }else{
                    return{};
                }
            }
        }
        return v;
    }
};
