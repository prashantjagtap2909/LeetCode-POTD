class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int multiplier = 60001;
        unordered_set<int> obsCordHashes;
        for (auto& obsCord : obstacles) {
            int oneDCord = getOneDCord(obsCord[0], obsCord[1], multiplier);
            obsCordHashes.insert(oneDCord);
        }

        int maxDistSq = 0;
        int currDir = 0;
        vector<int> currCord = {0, 0};
        vector<vector<int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        for (auto com : commands) {
            if (com > 0) {
                vector<int> dir = dirs[currDir];
                while (com-- > 0) {
                    int nextX = currCord[0] + dir[0];
                    int nextY = currCord[1] + dir[1];
                    int currOneDCord = getOneDCord(nextX, nextY, multiplier);
                    if (obsCordHashes.count(currOneDCord)) {
                        break;
                    }
                    currCord[0] = nextX;
                    currCord[1] = nextY;
                }
                maxDistSq = max(maxDistSq, currCord[0] * currCord[0] + currCord[1] * currCord[1]);
            } else {
                if (com == -2) {
                    currDir = (currDir + 3) % 4;
                } else {
                    currDir = (currDir + 1) % 4;
                }
            }
        }
        return maxDistSq;
    }

private:
    int getOneDCord(int x, int y, int mul) {
        return x + mul * y;
    }
};
