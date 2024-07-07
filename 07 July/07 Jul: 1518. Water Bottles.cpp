class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int res = numBottles , curr = numBottles;
        while(curr / numExchange != 0){
            int full = curr / numExchange;
            int left = curr - full * numExchange;
            res += full;
            curr = left + full;
        }
        return res;
    }
};
