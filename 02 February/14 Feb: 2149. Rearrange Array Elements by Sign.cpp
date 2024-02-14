class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
         vector<int> ans(nums.size());
        int idx[2]={-2, -1};
        for(int x: nums){
            int pos=(idx[x<0]+=2);
            ans[pos]=x;
        }
        return move(ans);  
    }
};
