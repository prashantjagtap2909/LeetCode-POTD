class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int res = 0;
        for(int l = 0 , r = people.size()-1 ; l <= r; r--){
            res++;
            if(people[l] <= limit-people[r]) l++;
        }
        return res;
    }
};
