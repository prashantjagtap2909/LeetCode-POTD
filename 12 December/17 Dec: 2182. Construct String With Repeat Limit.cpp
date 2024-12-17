class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        vector<int> freq(26, 0);
        for (char c : s) freq[c - 'a']++;
        priority_queue<pair<char, int>> pq;
        for (int i = 0; i < 26; i++) if (freq[i] > 0) pq.push({i + 'a', freq[i]});
        string result;
        while (!pq.empty()) {
            auto [ch, count] = pq.top(); pq.pop();
            int use = min(repeatLimit, count);
            result.append(use, ch);
            count -= use;
            if (count > 0) {
                if (!pq.empty()) {
                    auto [nextCh, nextCount] = pq.top(); pq.pop();
                    result.push_back(nextCh);
                    if (--nextCount > 0) pq.push({nextCh, nextCount});
                    pq.push({ch, count});
                }
            }
        }
        return result;
    }
};
