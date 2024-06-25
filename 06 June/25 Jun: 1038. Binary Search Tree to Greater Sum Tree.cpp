class Solution {
public:
    TreeNode* bstToGst(TreeNode* root) {
         vector<TreeNode*> stk;
        TreeNode* u = root;
        while(u) {
            stk.push_back(u);
            u = u -> right;
        }
        int greater = 0;
        while(stk.size()) {
            TreeNode* node = stk.back();
            stk.pop_back();
            greater += node -> val;
            node -> val = greater;
            node = node -> left;
            while(node != NULL) {
                stk.push_back(node);
                node = node -> right;
            }
        }
        return root;
    }
};
