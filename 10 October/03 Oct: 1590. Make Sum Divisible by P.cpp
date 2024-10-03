class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        long totalrem = accumulate(nums.begin(), nums.end(), 0l) % p;
        if(totalrem == 0) {
            return 0;
        }
        unordered_map<int, int> presums;
        presums[0] = -1;
        long sum = 0;
        int minlen = INT_MAX;
        for(int i = 0; i < n; i++) {
            sum += nums[i];
            long rem = sum % p;
            long target = (((rem - totalrem) % p) + p) % p;
            if(presums.contains(target)) {
                minlen = min(i - presums[target], minlen);
            }
            presums[rem] = i;
        }
        return (minlen == INT_MAX or minlen == n) ? -1 : minlen;
    }
};
