class Solution {
public:
    int timeConvertToMinutes(string time)
    {
        int hourToMinute = stoi(time.substr(0, 2)) * 60;
        int minute = stoi(time.substr(3, 2));
        return hourToMinute + minute;
    }

    int findMinDifference(vector<string>& timePoints) 
    {
        sort(begin(timePoints), end(timePoints));
        timePoints.push_back(timePoints[0]);
        int ans = INT_MAX, n = timePoints.size(), time_one, time_two;
        for(int i = 0; i < n - 1; i++)
        {
            time_one = timeConvertToMinutes(timePoints[i]);
            time_two = timeConvertToMinutes(timePoints[i + 1]);
            ans = min(ans, abs(time_one - time_two));
            ans = min(ans, abs(time_one - (1440 + time_two)));
        }
        return ans;
    }
};
