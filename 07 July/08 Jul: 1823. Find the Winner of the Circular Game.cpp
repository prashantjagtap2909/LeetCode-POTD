class Solution {
public:

    int solve(int n , int k){
        if(n == 1) return 0;

        return (solve(n-1, k) + k)%n;
    }

    int findTheWinner(int n, int k) {
        int res = solve(n,k)+1;
        return res;
    
    }
};
