class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<string>res;

        for(char ch = 'a'; ch <= 'z' ; ch++){
            int mini = INT_MAX;

            for(string word : words){
                int cnt = 0;
                for(char c : word){
                    if(c == ch){
                        cnt++;
                    }
                }
                mini = min(mini, cnt);
            }
            for(int i = 0 ; i < mini; i++){
                res.push_back(string(1,ch));
            }
            
        }
        return res;
    }
};
