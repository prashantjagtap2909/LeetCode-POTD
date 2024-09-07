
class Solution {
public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        return dfs(head, head, root);
    }
    
    bool dfs(ListNode* head, ListNode* cur, TreeNode* root) {
        if (cur == nullptr) return true;
        if (root == nullptr) return false; 
        
        if (cur->val == root->val) {
            cur = cur->next;
        } else if (head->val == root->val) {
            head = head->next;
        } else {
            cur = head; 
        }
        
        return dfs(head, cur, root->left) || dfs(head, cur, root->right);
    }
};
