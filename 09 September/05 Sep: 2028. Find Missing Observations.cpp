class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        int sum = 0;
        for(auto& x : rolls)
        {
            sum += x;
        }
        int missing_Sum = (m + n) * mean - sum;
        if(missing_Sum < n || missing_Sum > 6 * n)
        {
            return {};
        }
        int avg = missing_Sum / n;
        int balance = missing_Sum % n;
        vector<int> ans(n, avg); 
        for(int i = 0; i < balance; i++)
        {
            ans[i]++;
        }
        return ans;
    }
};
