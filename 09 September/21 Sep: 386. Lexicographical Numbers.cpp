class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<string>str;
        vector<int>res;
        while(n){
            str.push_back(to_string(n--));
        }
        sort(str.begin() , str.end());
        for(auto it:str){
            res.push_back(stoi(it));
        }
        return res;
    }
};
