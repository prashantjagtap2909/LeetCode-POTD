class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int>mp;
        for(int num : nums1){
            mp[num]++;
        }
        for(int num : nums2){
            if(mp[num] > 0) return num;
        }
        return -1;
    }
};
