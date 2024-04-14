
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        return dfs(root, false);
    }
    
    int dfs(TreeNode* node, bool isLeft) {
        if (!node) {
            return 0;
        }
        if (!node->left && !node->right) { 
            return isLeft ? node->val : 0;
        }
        int leftSum = dfs(node->left, true);    
        int rightSum = dfs(node->right, false); 
        return leftSum + rightSum;
    }
};
