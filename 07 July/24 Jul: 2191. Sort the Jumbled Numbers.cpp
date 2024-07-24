class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        int numCount = nums.size();
        vector<pair<int, int>> mappedNumAndIndex(numCount);

    for (int i = 0; i < numCount; ++i) {
        int originalNum = nums[i];
        string mappedNumStr = "";
        
        if (originalNum == 0) {
            mappedNumStr = to_string(mapping[0]);
        } else {
            while (originalNum > 0) {
                int digit = originalNum % 10;
                mappedNumStr = to_string(mapping[digit]) + mappedNumStr;
                originalNum /= 10;
            }
        }

        int mappedNum = stoi(mappedNumStr);
        mappedNumAndIndex[i] = {mappedNum, i};
    }

    sort(mappedNumAndIndex.begin(), mappedNumAndIndex.end());

    vector<int> sortedNums;
    for (const auto& pair : mappedNumAndIndex) {
        sortedNums.push_back(nums[pair.second]);
    }

    return sortedNums;
    }
};
