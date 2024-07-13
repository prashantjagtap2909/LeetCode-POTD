class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        vector<pair<int,pair<int,pair<int,char>>>> robots;
        int n = positions.size();
        for(int i=0;i<n;i++){
            robots.push_back({positions[i],{i,{healths[i],directions[i]}}});
        }
        sort(robots.begin(),robots.end());
        stack<pair<int,char>> st;
        vector<int> finalHealth(n,-1);

        for(int i=0;i<n;i++){
            int position = robots[i].first;
            int index = robots[i].second.first;
            int health = robots[i].second.second.first;
            char direction = robots[i].second.second.second;
            if(direction == 'R'){
                st.push({index,direction});
                finalHealth[index] = health;
            }else{
                while(!st.empty() && st.top().second == 'R'){
                    int rightIndex = st.top().first;
                    int rightHealth = finalHealth[rightIndex];
                    if(rightHealth > health){
                        finalHealth[rightIndex]--;
                        health = -1;
                        break;
                    }else if(rightHealth < health){
                        finalHealth[rightIndex] = -1;
                        health --;
                        st.pop();
                    }else{
                        finalHealth[rightIndex] = -1;
                        health = -1;
                        st.pop();
                        break;
                    } 
                }
                if(health > 0){
                   finalHealth[index] = health;
                }
            }
        }
        vector<int> result;
        for(auto healthy : finalHealth){
            if(healthy > 0) result.push_back(healthy);
        }
        return result;
    }
};
