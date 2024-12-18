class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        vector<int> v(n); 

        for (int i = 0; i < n; i++) {
            v[i] = prices[i]; 
            for (int j = i + 1; j < n; j++) {
                if (prices[j] <= prices[i]) { 
                    v[i] = prices[i] - prices[j]; 
                    break; 
                }
            }
        }
        return v;
    }
};
