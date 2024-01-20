class Solution {
public:
int mod = 1e9+7;
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        long long res = 0;
        stack<int>st;
        for(int i = 0 ; i <= n ; i++){
            while(st.size() && (i == n || arr[st.top()] > arr[i])){
                int j = st.top();
                st.pop();
                int k = st.empty() ? -1 : st.top();
                res += (long long) arr[j] * (i - j)*(j - k);
            }
            st.push(i);
        }
        return (int) (res%mod);
    }
};
