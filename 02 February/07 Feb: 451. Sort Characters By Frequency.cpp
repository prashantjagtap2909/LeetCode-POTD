class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> charCount;
        for (char c : s) {
            charCount[c]++;
        }
        vector<char> sortedChars;
        for (const auto& entry : charCount) {
            sortedChars.push_back(entry.first);
        }
        sort(sortedChars.begin(), sortedChars.end(), [&](char a, char b) {
            return charCount[a] > charCount[b];
        });
        string result;
        for (char c : sortedChars) {
            result += string(charCount[c], c);
        }
        return result;
    }
};
