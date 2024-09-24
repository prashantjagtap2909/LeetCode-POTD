class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
         int maxi = 0;
        
        for (int i = 0; i < arr1.size(); i++) {
            string first = to_string(arr1[i]);
            for (int j = 0; j < arr2.size(); j++) {
                string second = to_string(arr2[j]);
                int minLength = min(first.size(), second.size());
                int k = 0;
                while (k < minLength && first[k] == second[k]) {
                    k++;
                }
                maxi = max(maxi, k);
            }
        }
        
        return maxi;
    }
};
