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
    TreeNode* replaceValueInTree(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);

        vector<int>store;
        int depth = 0, size, sum;
        while(!q.empty())
        {
            sum = 0, size = q.size();
            while(size--)
            {
                auto node = q.front(); q.pop();
                sum += node->val;

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            store.push_back(sum);
        }
        store.push_back(store.back());
        
        q.push(root);
        root->val = 0;
        while(!q.empty())
        {
            depth += 1;
            size = q.size();
            while(size--)
            {
                sum = store[depth];
                auto node = q.front(); q.pop();
                
                if(node->left)
                {
                    q.push(node->left);
                    sum -= node->left->val;
                }
                if(node->right)
                {
                    q.push(node->right);
                    sum -= node->right->val;
                }

                if(node->left) node->left->val = sum;
                if(node->right) node->right->val = sum;
            }
        }
        return root;
    }
};
