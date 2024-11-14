class Solution {
public:
    int minimizedMaximum(int storeCount, vector<int>& productQuantities) {
        int maxQuantity = *max_element(productQuantities.begin(), productQuantities.end());
        int left = 1;
        int right = maxQuantity;
        int result = 0;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (canDistributeProducts(mid, storeCount, productQuantities)) {
                result = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        
        return result;
    }

private:
    bool canDistributeProducts(int maxProductsPerStore, int storeCount, const vector<int>& quantities) {
        int requiredStores = 0;
        
        for (int quantity : quantities) {
            requiredStores += (quantity + maxProductsPerStore - 1) / maxProductsPerStore;
        }
        
        return requiredStores <= storeCount;
    }
};
