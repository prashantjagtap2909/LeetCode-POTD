class Solution {
public:
int get_dia(vector<vector<int>>& edges){
    unordered_map<int,list<int>>g;                                                              
    vector<int>degree(edges.size()+1);
    for(auto& x:edges){
        g[x[0]].push_back(x[1]);
        g[x[1]].push_back(x[0]);
        degree[x[0]]++;
        degree[x[1]]++;
    }
    queue<int>q;
    for(int i=0;i<degree.size();i++) {
        if(degree[i]==1){
            degree[i]--;
           q.push(i);
        } 
    }
    int total=edges.size()+1;
    int min_dia=0;
    while(total>2){ 
        int curr_size=q.size();
        total-=curr_size;
        min_dia++;
        while(curr_size--){
            int tope=q.front();
            q.pop();
            for(auto z:g[tope]){
             if(--degree[z]==1) q.push(z);
            }
        }
    }
     return (total==2)?2*min_dia+1:2*min_dia;
}
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int d1=get_dia(edges1);
        int d2=get_dia(edges2);
        return max({d1,d2,(d1+1)/2+(d2+1)/2+1});

    }
};
