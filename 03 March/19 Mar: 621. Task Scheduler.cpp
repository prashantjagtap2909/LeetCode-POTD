class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        if (n == 0)
            return tasks.size();

        vector<int> cnt(26, 0);
        for (char task : tasks)
            cnt[task - 'A']++;

        int maxCount = 0;
        int sameMaxCount = 0;

        for (int i = 0; i < 26; i++) {
            if (cnt[i] > maxCount) {
                maxCount = cnt[i];
                sameMaxCount = 1;
            } else if (cnt[i] == maxCount) {
                sameMaxCount++;
            }
        }

        int res = (n + 1) * (maxCount - 1) + sameMaxCount;
        return max(res, (int)tasks.size());
    }
};
