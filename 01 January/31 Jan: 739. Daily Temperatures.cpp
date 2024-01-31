class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperature) {
        vector<int>res(temperature.size(), 0);
        vector<int>st;

        for(int i = temperature.size()-1; i >= 0 ; --i){
            int curr = temperature[i];

            while(!st.empty() && curr >= temperature[st.back()]){
                st.pop_back();
            }
            if(!st.empty()){
                res[i] = st.back()-i;
            }
            st.push_back(i);
        }
        return res;
    }
};
