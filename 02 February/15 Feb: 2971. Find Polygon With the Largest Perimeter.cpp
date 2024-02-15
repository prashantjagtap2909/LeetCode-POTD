class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        int n=nums.size();
        long long perimeter=accumulate(nums.begin(), nums.end(), 0LL);
        priority_queue<int> heap(nums.begin(), nums.end());
        for(int i=n-1; i>=2; i--){
           int largest=heap.top();
           heap.pop();
           if (largest<perimeter-largest) return perimeter;
           perimeter-=largest;
        }
        return -1;
    }
};
