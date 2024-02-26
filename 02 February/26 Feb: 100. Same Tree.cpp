class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q) return 1;
        if(!p || !q) return 0;
        return (p->val == q->val) && isSameTree(p->left, q->left)
                                && isSameTree(p->right, q->right);
    }
};
