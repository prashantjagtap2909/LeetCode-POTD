class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        int n=intervals.size();
        vector<int> P;
        P.reserve(n*2);
        for(auto& it: intervals){
            int x=it[0], y=it[1]+1;
            P.push_back((x<<1)+1);
            P.push_back(y<<1);
        }
        sort(P.begin(), P.end());
        int cnt=0, x=0;
        for(int z: P){
            x+=(z&1)?1:-1;
            cnt=max(cnt, x);
        }
        
        return cnt;    
    }
};
