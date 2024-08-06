class Solution {
public:
    int minimumPushes(string word) {
        vector<int> hashMap(26,0);
        for(auto &c: word){
            hashMap[c-'a']++;
        }
        sort(hashMap.begin(),hashMap.end(),greater<int>());
        int ans = 0;
        int push = 1;
        int keyCnt = 0;
        for(auto &freq: hashMap){
            if(freq == 0) break;
            ans += freq * push;
            keyCnt++;
            if(keyCnt % 8 == 0) push++;
        }
        return ans;
    }
};
