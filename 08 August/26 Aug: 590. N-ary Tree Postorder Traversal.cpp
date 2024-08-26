
class Solution {
public:
     vector<int> ans;
    vector<int> postorder(Node* root) {
        if (!root) return ans;
        for(auto& child: root->children)
            postorder(child);
        ans.push_back(root->val);
        return ans;
    }
};
