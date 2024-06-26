class Solution {
public:
    vector<int>a;
    void inorder(TreeNode*root)
    {
        if(root)
        {
            inorder(root->left);
            a.push_back(root->val);
            inorder(root->right);
        }
    }

    TreeNode* buildTree(int s, int e)
    {
        if(s > e) return NULL;
        int mid = (s+e)/2;
        TreeNode* root = new TreeNode(a[mid]);
        root->left = buildTree(s, mid-1);
        root->right = buildTree(mid+1, e);
        return root;
    }

    TreeNode* balanceBST(TreeNode* root) 
    {
        inorder(root);
        return buildTree(0, a.size()-1);
    }
};
