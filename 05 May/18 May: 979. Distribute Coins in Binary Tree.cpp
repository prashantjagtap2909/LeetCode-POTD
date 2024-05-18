class Solution {
public:
    int distributeCoins(TreeNode* root, TreeNode* parent = NULL) {
        if(!root) return 0;
        int moves = distributeCoins(root->left, root)+distributeCoins(root->right, root);
        int cnt = root->val -1 ;
        if(parent) parent->val += cnt;
        moves += abs(cnt);
        return moves;
    }
};
