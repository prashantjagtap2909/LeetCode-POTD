class Solution {
private:
    unordered_map<string, int> mp;
    unordered_map<string, int> memo;

    int solve(string s) {
        if (s.empty()) {
            return 0;
        }

        if(memo.find(s) != memo.end()){
            return memo[s];
        }

        int extra = INT_MAX;
        string temp = "";

        for (int i = 0; i < s.size(); i++) {
            temp += s[i];
            if (mp.find(temp) != mp.end()) {
                extra = min(extra, solve(s.substr(i + 1)));
            }
        }

        extra = min(extra, 1 + solve(s.substr(1)));
        memo[s] = extra;
        
        return extra;
    }

public:
    int minExtraChar(string s, vector<string>& dict) {
        for (auto& it : dict) {
            mp[it]++;
        }
        return solve(s);
    }
};
