class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        using ll = long long;
        int n = nums.size(); 
        long long ans = LLONG_MAX;
        long long sum =0;
        priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>pq;
        for(ll i=0; i<n; i++){
            sum += nums[i];
            if(sum>=k){
                ans = min(ans,i+1);
            }
            while(!pq.empty() && (sum-pq.top().first)>=k){
              
                ans = min(ans,i-pq.top().second);
                pq.pop();
            }
            pq.push({sum,i});
        }
        return ans ==INT_MAX?-1:(ans);
    }
};
