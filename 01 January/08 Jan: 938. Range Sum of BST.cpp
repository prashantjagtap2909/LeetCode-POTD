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

    int dfs(TreeNode* root, int low , int high){
        if(root == NULL) return 0;

        int res = 0;

        if(root->val >= low && root->val <= high){
            res = root->val;
        }
        if(root ->val <= low){
            res += dfs(root->right , low , high);
        }else if(root->val >= high){
            res += dfs(root->left, low , high);
        }else{
            res += dfs(root->right , low , high);
            res += dfs(root->left , low , high);
        }
        return res;
    }

    int rangeSumBST(TreeNode* root, int low, int high) {
        return dfs(root, low , high);
    }
};
