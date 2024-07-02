class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> m;
        vector<int> v;

        for(int num : nums1) {
            m[num]++;
        }
        for(int num : nums2) {
            if(m[num] > 0) {
                v.push_back(num);
                m[num]--;
            }
        }

        return v;
    }
};
