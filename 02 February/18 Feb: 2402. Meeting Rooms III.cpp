class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        int len=size(meetings);
        vector<long long>endtime(n,0);
        vector<int>count(n,0);
        sort(begin(meetings),end(meetings));
        for(int i=0;i<len;i++){
            int start=meetings[i][0];
            int time=meetings[i][1]-start;
            bool isdelay = true;
            long long mindelay=LLONG_MAX;
            int indx;
            for(int j=0;j<n;j++){
                if(endtime[j]<=start){
                    endtime[j]=meetings[i][1];
                    count[j]++;
                    isdelay = false;
                    break;
                }else{
                    if(endtime[j]<mindelay){
                        mindelay=endtime[j];
                        indx=j;
                    }
                }
            }
            if(isdelay){
                endtime[indx]+=time;
                count[indx]++;
            }
        }
        int res=0;
        for(int i=0;i<n;i++){
            cout<<count[i]<<" ";
            if(count[i]>count[res]){
                res =i;
            }
        }
        return res;
    }
};
