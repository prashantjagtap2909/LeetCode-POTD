class Solution {
public:

    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> chair;
        priority_queue<pair<pair<int,int>,int>, vector<pair<pair<int,int>,int>>, greater<pair<pair<int,int>,int>>> waiting;
        priority_queue<int, vector<int>, greater<int>> freeChair;
        int ch = 0;

        unordered_map<int,int> m;

        for(int i=0; i<times.size(); i++) waiting.push({{times[i][0],times[i][1]}, i});
    
        while(waiting.size()) {
            
            auto x = waiting.top(); waiting.pop();
            int arr = x.first.first;
            int dep = x.first.second;
            int fnd = x.second;

            while(chair.size() and arr >= chair.top().first){
                freeChair.push(chair.top().second);
                chair.pop();
            }
            
            if(freeChair.size()){
                int chno = freeChair.top();
                chair.push({dep, chno});
                m[fnd] = chno;
                freeChair.pop();
            }
            else{
                chair.push({dep, ch});
                m[fnd] = ch;
                ch++;
            }
        }

        return m[targetFriend];
    }
};
