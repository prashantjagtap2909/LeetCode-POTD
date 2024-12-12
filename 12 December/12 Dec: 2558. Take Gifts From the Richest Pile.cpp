class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> q;
        long long res = 0;
        for (int i : gifts) {
            q.push(i);
            res += i;
        }
        while (k--) {
            int v = q.top();
            res -= (v - sqrt(v));
            q.pop();
            q.push(sqrt(v));
        }
        return res;
    }
};
