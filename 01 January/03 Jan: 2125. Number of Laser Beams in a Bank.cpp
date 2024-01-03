class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int n = bank.size(), m = bank[0].size();
        int prev = 0 , curr = 0 , res = 0;
        for(int i = 0 ; i < n ; i++){
            curr = 0;
            for(int j = 0 ; j < m ; j++){
                if(bank[i][j] == '1'){
                    curr++;
                }
            }
            if(curr != 0){
                res += (curr * prev);
                prev = curr;
            }
        }
        return res;
    }
};
