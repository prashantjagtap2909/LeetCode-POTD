class Solution {
public:
    int maximumSwap(int num) {
        string ans = to_string(num);
        int len = ans.length();
        vector<char> v(len, '0');
        char maxDigit = '0';
        unordered_map<char, int> mp;

        for (int i = len - 1; i >= 0; i--) {
            if (ans[i] > maxDigit) {
                maxDigit = ans[i];
                mp[maxDigit] = i;
            }
            v[i] = maxDigit;
        }

        for (int i = 0; i < len; i++) {
            if (v[i] > ans[i]) {
                char temp = ans[i];
                ans[i] = v[i];
                ans[mp[v[i]]] = temp;
                break;
            }
        }

        return stoi(ans);
    }
};
