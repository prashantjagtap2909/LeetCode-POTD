
class Solution {
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        bool flag = false; 
        while (!q.empty()) {
            int sz = (int)q.size(); 
            vector<TreeNode*> v;
            for (int i = 0; i < sz; i++) {
                if (q.front() == NULL) {
                    q.pop();
                    continue;
                }
                v.push_back(q.front()); 
                q.push(q.front()->left);  
                q.push(q.front()->right); 
                q.pop(); 
            }
            if (flag) {
                int L = 0, R = (int)v.size() - 1;
                while (L <= R) {
                    swap(v[L++]->val, v[R--]->val);  
                }
            }
            flag = (!flag); 
        }
        return root;
    }
};
