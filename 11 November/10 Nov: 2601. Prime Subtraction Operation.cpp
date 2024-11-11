class Solution {
    vector<int> sieve(){
        vector<int> prime;
        int isPrime[1002];
        memset(isPrime, 1, sizeof(isPrime));
        isPrime[1] = 0;
        for(int i=2; i<1002; i++){
            if(isPrime[i]){
                prime.push_back(i);
                for(int j=i*i; j<1002; j+=i)
                    isPrime[j] = 0;
            }
        }
        return prime;
    }
public:
    bool primeSubOperation(vector<int>& nums) {
        int n = nums.size();
        vector<int> prime = sieve();
        for(int i=n-2; i>=0; i--){
            if(nums[i] < nums[i+1]) continue;
            int diff = nums[i]-nums[i+1];
            auto it = upper_bound(prime.begin(), prime.end(), diff);
            if(it==prime.end() || *it >= nums[i]){
                return false;
            }
            nums[i] -= *it;
        }
        return true;
    }
};
