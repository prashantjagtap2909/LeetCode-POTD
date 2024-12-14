class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        int n=nums.size();
        long long count=0;
        multiset<int> hasX;
        for(int l=0, r=0; r<n; r++){
            hasX.insert(nums[r]);
            while(l<r && *prev(hasX.end())-*hasX.begin()>2){
                auto it=hasX.find(nums[l]);
                hasX.erase(it);
                l++;
            }
            count+=r-l+1LL;
        }
        return count;
    }
};
