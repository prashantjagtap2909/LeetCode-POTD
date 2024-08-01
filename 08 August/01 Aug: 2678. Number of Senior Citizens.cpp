class Solution {
public:
    int countSeniors(vector<string>& details) {
        int count = 0;
        for(auto it : details){
            int age = stoi(it.substr(11,2));
            if(age > 60) count++;
        }
        return count;
    }
};
