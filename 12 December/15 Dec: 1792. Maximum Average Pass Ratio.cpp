class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& nums, int ex) {
        priority_queue<pair<double,int>>q;
        int n=nums.size();
        double ans=0;
        for(int i=0;i<nums.size();i++){
            double w=(double)(nums[i][0]+1)/(double)(nums[i][1]+1);
            double y=(double)nums[i][0]/(double)nums[i][1];
            ans+=y/n;
            q.push({w-y,i});
        }
        while(ex--){
            auto d=q.top().second;
            ans+=q.top().first/n;
            q.pop();
            nums[d][0]++;
            nums[d][1]++;
            double w=(double)(nums[d][0])/(double)(nums[d][1]);
            double x=(double)(nums[d][0]+1)/(double)(nums[d][1]+1);
            q.push({x-w,d});   

        }
        return ans;
    }
};
