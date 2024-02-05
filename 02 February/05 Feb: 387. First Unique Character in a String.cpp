class Solution {
public:
    int firstUniqChar(string s) {
         vector<int> oc(26);
        for (auto i : s) oc[i - 'a']++;
        for (int i = 0; i < s.size(); i++) {
            if (oc[s[i] - 'a'] == 1) return i;
        }
        return -1;
    }
};
