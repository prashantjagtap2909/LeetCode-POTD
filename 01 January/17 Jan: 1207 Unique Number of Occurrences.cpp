class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> cur;
        for (int x: arr){
            cur[x]++;
        }
        unordered_set<int> S;
        for (auto& [x,c]: cur){
            if (S.count(c)>=1) return 0;
            S.insert(c);
        }
        return 1;
    }
};
