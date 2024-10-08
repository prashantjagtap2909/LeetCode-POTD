class Solution {
public:
    int minSwaps(string s) {
        stack<char> st;
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == ']' && st.empty()) {
                continue;
            }
            else if(s[i] == ']' && st.top() == '[') {
                st.pop();
            }
            else {
                st.push('[');
            }
        }
        return (st.size() + 1) / 2;
    }
};
