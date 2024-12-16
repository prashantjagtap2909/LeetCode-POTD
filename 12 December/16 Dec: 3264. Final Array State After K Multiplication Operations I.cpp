class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int m) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for(int i = 0; i < nums.size(); i++) {
            pq.push({nums[i], i});
        }
        while(k--) {
            auto it = pq.top();
            pq.pop();
            nums[it.second] = m * it.first;
            pq.push({m * it.first, it.second}); 
        }
        return nums;
    }
};
