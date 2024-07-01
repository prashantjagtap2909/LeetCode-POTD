class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int len=0;
        for(int it: arr){
            len=(it&1)?len+1:0;
            if (len==3) return 1;
        }
        return 0;
    }
};
