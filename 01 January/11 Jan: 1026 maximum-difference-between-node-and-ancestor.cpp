/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int ans = 0;
    void dfs(TreeNode* root, int mx, int mn){
        if(root==NULL){
            return;
        }
        ans = max(ans,abs(root->val-mx));
        ans = max(ans,abs(root->val-mn));
        if(root->val>mx){
            mx = root->val;
        }
        if(root->val<mn){
            mn = root->val;
        }
        dfs(root->left,mx,mn);
        dfs(root->right,mx,mn);
    }
    int maxAncestorDiff(TreeNode* root) {
        dfs(root,root->val,root->val);
        return ans;
    }
};
