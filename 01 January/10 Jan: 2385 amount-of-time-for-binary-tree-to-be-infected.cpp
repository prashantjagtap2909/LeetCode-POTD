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
private:
    static int height(TreeNode* n){
        if (!n)
            return 0;
        return 1 + max(height(n->right), height(n->left));
    }
    static pair<bool, int> traverse(TreeNode* n, int targetVal, int& targetSubtreeHeight, int& maxIndirect){
        if (!n)
            return {false, 0};
        else if (n->val == targetVal){
            targetSubtreeHeight = max(height(n->left), height(n->right));
            return {true, 0};
        }
        else{
            auto l = traverse(n->left, targetVal, targetSubtreeHeight, maxIndirect);
            auto r = traverse(n->right, targetVal, targetSubtreeHeight, maxIndirect);
            if (l.first){
                maxIndirect = max(maxIndirect, 1 + l.second + r.second);
                return {true, 1 + l.second};
            }
            else if (r.first) {
                maxIndirect = max(maxIndirect, 1 + l.second + r.second);
                return {true, 1 + r.second};
            }
            else{
                return {false, 1 + max(l.second, r.second)};
            }
        }
    }
public:
    int amountOfTime(TreeNode* root, int start) 
    {
        int targetLeafLen = 0, maxIndirect = 0;
        traverse(root, start, targetLeafLen, maxIndirect);
        return max(maxIndirect, targetLeafLen);
    }
};
