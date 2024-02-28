class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*>q;

        q.push(root);
        TreeNode *a=NULL;
        while(!q.empty()){
            a = q.front();
            q.pop();

            if(a->right){
                q.push(a->right);
            }
            if(a->left){
                q.push(a->left);
            }
        }
        return a->val;
    }
};
