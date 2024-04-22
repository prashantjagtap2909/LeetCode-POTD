class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        int pow10[] = {1, 10, 100, 1000};
        int visit[10000] = {0}; 
        for(string dead : deadends) {
            visit[stoi(dead)] = 2;
        }
        int src = 0, dest = stoi(target), steps = 0, dir = 1;
        if(visit[src] == 2 || visit[dest] == 2) return -1;
        if(src == dest) return 0;
        queue<int> forward, backward;
        forward.push(src);
        visit[src] = 1;
        backward.push(dest);
        visit[dest] = -1;
        while(!forward.empty() && !backward.empty()) {
            if(forward.size() > backward.size()) {
                swap(forward, backward);
                dir = -dir;
            }
            steps++;
            int size = forward.size();
            while(size-- > 0) {
                int cur = forward.front();
                forward.pop();
                for(int p : pow10) {
                    int d = (cur / p) % 10;
                    for(int i = -1; i <= 1; i += 2) {
                        int z = d + i;
                        z = z == -1 ? 9 : (z == 10 ? 0 : z);
                        int next = cur + (z - d) * p;
                        if(visit[next] == -dir) return steps;
                        if(visit[next] == 0) {
                            forward.push(next);
                            visit[next] = dir;
                        }
                    }
                }
            }
        }
        return -1;
    }
};
