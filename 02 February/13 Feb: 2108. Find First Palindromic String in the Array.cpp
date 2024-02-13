class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        string temp;
        for(string& s : words){
            temp = s;
            reverse(temp.begin(), temp.end());
            if(s == temp) return s;
        }
        return "";
    }
};
