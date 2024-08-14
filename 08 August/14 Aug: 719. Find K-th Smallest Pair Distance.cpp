class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) 
    {
        int n = nums.size();
        sort(begin(nums), end(nums));

        auto countPairs = [&](int mid)
        {
            int left = 0, count = 0;
            for(int right = 0; right < n; right++)
            {
                while(nums[right] - nums[left] > mid) left++;
                count += right - left;
            }
            return count < k;
        };

        int left = 0, right = nums[n-1] - nums[0], mid;
        while(left < right)
        {
            mid = left + (right - left) / 2;
            if(countPairs(mid)) left = mid + 1;
            else right = mid;
        }
        return left;
    }
};
