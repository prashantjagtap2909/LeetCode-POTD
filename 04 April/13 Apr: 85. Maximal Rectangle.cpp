class Solution {
public:

    int largestRectangleArea(vector<int>& m) {
        int n = m.size();
        
        stack<int>st;

        int ans = 0;
        int index;

        for(int i = 0 ; i < n ;i++){
            while(!st.empty() && m[st.top()] > m[i]){
                index = st.top();
                st.pop();

                if(!st.empty())
                ans = max(ans , m[index]*(i-st.top()-1));

                else 
                ans = max(ans , m[index]*i);
            }
            st.push(i);
        }


        while(!st.empty()){
            index = st.top();
                st.pop();

                if(!st.empty())
                ans = max(ans , m[index]*(n-st.top()-1));

                else 
                ans = max(ans , m[index]*n);
        }

        return ans;
        
    }



    int maximalRectangle(vector<vector<char>>& matrix) {
        int res = 0;
        int row = matrix.size();
        int col = matrix[0].size();

        vector<int>heights(col , 0);
        for(int i = 0 ; i < row ; i++){
            for(int j = 0 ; j < col ; j++){
                if(matrix[i][j] == '0'){
                    heights[j] = 0;
                    
                }else
                    heights[j]++;
            }
            res = max(res, largestRectangleArea(heights));
        }
        return res;

    }
};
