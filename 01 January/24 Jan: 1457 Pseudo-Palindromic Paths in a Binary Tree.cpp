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
    map<int,int> mp;
    int findPaths(TreeNode* root, int c){
        if(root->left==NULL && root->right==NULL){
            mp[root->val]++;
            if(mp[root->val]&1){
                c++;
            }else{
                c--;
            }
            mp[root->val]--;
            if(c<=1){
                return 1;
            }
            
            return 0;
        }
        int ans = 0;
        mp[root->val]++;
        if(mp[root->val]&1){
            c++;
        }else{
            c--;
        }
        if(root->left!=NULL){  
            ans+=findPaths(root->left,c);
        }
        if(root->right!=NULL){
            ans+=findPaths(root->right,c);
        }
        mp[root->val]--;
        return ans;

    }
    int pseudoPalindromicPaths (TreeNode* root) {
        return findPaths(root,0);
    }
};
