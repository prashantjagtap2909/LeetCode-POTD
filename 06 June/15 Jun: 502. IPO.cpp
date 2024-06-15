class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int,int>> vec;
        for(int i=0; i<profits.size(); i++){
            vec.push_back({profits[i],capital[i]});
        }
        auto comp = [](pair<int,int> a, pair<int,int> b){
            return a.second < b.second;
        };
        sort(vec.begin(),vec.end(),comp);
        priority_queue<int> pq;
        int j=0;
        while(j<profits.size() && vec[j].second <= w){
            pq.push(vec[j].first);
            j++;
        }
        while(!pq.empty() && k > 0){
            w += pq.top();
            pq.pop();
            while(j<profits.size() && vec[j].second <= w){
                pq.push(vec[j].first);
                j++;
            }
            k--;
        }
        return w;
    }
};
