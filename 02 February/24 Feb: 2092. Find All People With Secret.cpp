class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        vector<pair<int,int>> adj[n];
        vector<int> dis(n,INT_MAX);
        dis[0] = 0;
        dis[firstPerson] = 0;
        for(auto i:meetings){
            int a = i[0];
            int b = i[1];
            int time = i[2];
            adj[a].push_back({b,time});
            adj[b].push_back({a,time});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,0});
        if(firstPerson != 0) pq.push({0,firstPerson});
        unordered_set<int> s;
        s.insert(0);
        s.insert(firstPerson);
        while(pq.empty() == false){
            pair<int,int> p = pq.top();
            pq.pop();
            int d = p.first;
            int node = p.second;
            s.insert(node);
            for(auto i:adj[node]){
                if(dis[i.first] > d and i.second >= d  and s.find(i.first) == s.end()){
                    dis[i.first] = i.second;
                    pq.push({i.second,i.first});
                }
            }
        }
        vector<int> res;
        for(auto i:s){
            res.push_back(i);
        }
        return res;
    }
};
