class Solution {
public:
    int passThePillow(int n, int time) {
         int stand = 1, flag = 1;
        while(time--)
        {
            if(flag)
            {
                stand++;
                if(stand == n) flag = !flag;
            }
            else 
            {
                stand--;
                if(stand == 1) flag = !flag;
            }
        }
        return stand;
    }
};
