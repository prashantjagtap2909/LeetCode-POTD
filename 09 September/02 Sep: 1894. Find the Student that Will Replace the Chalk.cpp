class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long n = chalk.size(), sum, left;
        vector<long> pref(n);
        pref[0] = chalk[0];
        for(int i = 1;i<n;i++) pref[i] = pref[i-1] + chalk[i];
        sum = pref[n-1];
        if(k%sum == 0) return 0;
        left = k - (k/sum)*sum;
        return upper_bound(pref.begin(), pref.end(), left) - pref.begin();
    }
};
