class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        vector<int> mod_k(k, 0);
        int prefix = 0;
        mod_k[0] = 1;

        for (int x : nums) {
            prefix = (prefix + x) % k;
            prefix += ((prefix < 0) ? k : 0);
            mod_k[prefix]++;
        }
        return accumulate(mod_k.begin(), mod_k.end(), 0,
                          [](int sum, int x) { return sum + x * (x - 1) / 2; });
    }
    
};
