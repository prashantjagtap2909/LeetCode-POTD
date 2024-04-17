
class Solution {
public:
    string ans="|", s;
    void f(TreeNode* node){
        if (!node) return;
        s+=(node->val+'a');
        if (!node->left && !node->right){
            string t=s;
            reverse(t.begin(), t.end());
            ans=min(ans, t);
        }
        f(node->left);
        f(node->right);
        s.pop_back();
    }
    string smallestFromLeaf(TreeNode* root) {
        f(root);
        return ans;
    }
};
