class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        bitset<1001> seen[2]={0};
        for(int x: arr){
            int z=abs(x);
            if ((z<=500 && seen[x<0][2*z])|| (z%2==0 && seen[x<0][z/2]))
                return 1;
            seen[x<0][z]=1;
        }
        return 0;
    }
};
