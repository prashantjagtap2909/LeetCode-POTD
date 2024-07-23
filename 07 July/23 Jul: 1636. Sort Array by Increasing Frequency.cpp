class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (auto num : nums) {
            ++freq[num];
        }
        sort(nums.begin(), nums.end(), [&freq](int a, int b) {
            return freq[a] == freq[b] ? a > b : freq[a] < freq[b];
        });
        return nums;
    }
};
