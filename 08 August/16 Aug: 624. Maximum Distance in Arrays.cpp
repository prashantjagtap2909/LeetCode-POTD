class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int minVal = arrays[0][0];
        int maxVal = arrays[0].back();
        int maxDistance = 0;

        for(int i = 1; i < arrays.size(); i++) {
            maxDistance = max(maxDistance, max(abs(arrays[i].back() - minVal), abs(maxVal - arrays[i][0])));
            minVal = min(minVal, arrays[i][0]);
            maxVal = max(maxVal, arrays[i].back());
        }

        return maxDistance;
    }
};
