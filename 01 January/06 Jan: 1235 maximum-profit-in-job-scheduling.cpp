class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int jobsCnt = profit.size();
        vector<tuple<int,int,int>> jobs(jobsCnt);
        for(int i = 0 ; i < jobsCnt; i++){
            jobs[i] = {endTime[i], startTime[i], profit[i]};
        }
        sort(jobs.begin(), jobs.end());
        vector<int>dp(jobsCnt + 1);
        
        for(int i = 0 ; i < jobsCnt; i++){
            auto[endTime, startTime, profit] = jobs[i];

            int latest = upper_bound(jobs.begin() , jobs.begin()+i, startTime, [&](int time, const auto& job)->bool{
                return time < get<0>(job);
            }) - jobs.begin();

            dp[i+1] = max(dp[i], dp[latest] + profit);
        }
        return dp[jobsCnt];
    }
};
