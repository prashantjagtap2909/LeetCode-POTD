class Solution {
    int factor = 1024;
    vector<int> dir = {-1,0,1,0,-1};
public:
    int minimumTime(vector<vector<int>>& grid) {
        if(grid[0][1] > 1 && grid[1][0] > 1) return -1;
        int m = grid.size();
        int n = grid[0].size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0,0});
        grid[0][0] = -1;
        while(!pq.empty()){
            auto [cost, pos] = pq.top();
            pq.pop();
            int x = pos / factor;
            int y = pos % factor;
            if(x == m-1 && y == n-1)
                return cost;
            for(int i=0; i<4; ++i){
                int newx = x + dir[i];
                int newy = y + dir[i+1];
                if(newx>=0 && newx<m && newy>=0 && newy<n && grid[newx][newy] != -1){
                    int newcost = cost + 1;
                    if(newcost < grid[newx][newy]){
                        if((grid[newx][newy] - newcost) % 2 == 1)
                            newcost = grid[newx][newy] + 1;
                        else
                            newcost = grid[newx][newy];
                    }
                    pq.push({newcost, (newx * factor + newy)});
                    grid[newx][newy] = -1;
                }
            }
        }
        return -1000; 
    }
};
