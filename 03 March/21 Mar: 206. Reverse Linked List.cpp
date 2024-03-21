class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        vector<int>res;
        ListNode *temp = head;

        while(temp != NULL){
            res.push_back(temp->val);
            temp = temp->next;

        };

        int i = res.size()-1;
        temp = head;
        while(temp){
            temp->val = res[i];
            i--;
            temp = temp->next;
        }
        return head;
    }
};
