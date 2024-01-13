class Solution {
public:
    int minSteps(string s, string t) {
        int freq[26] = {0};
        for(char c: s) freq[c-'a']++;
        for(char c: t) freq[c-'a']--;
        int res = 0;
        for(int i = 0; i <26 ; i++){
            if(freq[i] > 0)
                res += freq[i];
        }
        return res;
    }
};
