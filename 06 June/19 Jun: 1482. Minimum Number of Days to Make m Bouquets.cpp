class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int l = 1, r = 1e9;
        int ans = -1;
        while(l <= r) {
            int mid = l + (r - l) / 2;
            int consecutiveLength = 0, bonquets = 0;
            for(int i = 0; i < bloomDay.size(); i++) {
                if(bloomDay[i] <= mid) {
                    consecutiveLength++;
                    if(consecutiveLength >= k) {
                        consecutiveLength = 0;
                        bonquets++;
                    }
                } else {
                    consecutiveLength = 0;
                }
            }
            if(bonquets >= m) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};
