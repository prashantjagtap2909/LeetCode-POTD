class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> count(1001);
        for(int i = 0; i < arr1.size(); i++) {
            count[arr1[i]]++;
        }
        
        vector<int> ans;
        for(int i = 0; i < arr2.size(); i++) {
            while(count[arr2[i]]--) {
                ans.push_back(arr2[i]);
            }
        }
        
        for(int i = 0; i < count.size(); i++) {
            while(count[i]-- > 0) ans.push_back(i);
        }
        return ans;
    }
};
