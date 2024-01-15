class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& arr) {
        vector<vector<int>> out;
        map<int,int> mp;
        int n = arr.size();
        vector<int> brr;
        for(int i = 0;i<n;i++){
            mp[arr[i][1]]++;
            brr.push_back(arr[i][0]);
            brr.push_back(arr[i][1]);
            
        }
        vector<int> a;
        vector<int> b;
        for(int i = 0;i<brr.size();i++){
            if(mp[brr[i]]==0){
                a.push_back(brr[i]);
            }else if(mp[brr[i]]==1){
                b.push_back(brr[i]);
            }
        }
        
        set<int> v;
        for(auto i:a){
            v.insert(i);
        }
        a.clear();
        for(auto i : v){
            a.push_back(i);
        }
        v.clear();
        out.push_back(a);
        for(auto i:b){
            v.insert(i);
        }
        b.clear();
        for(auto i:v){
            b.push_back(i);
        }
        v.clear();
        out.push_back(b);
        return out;
    }
};
