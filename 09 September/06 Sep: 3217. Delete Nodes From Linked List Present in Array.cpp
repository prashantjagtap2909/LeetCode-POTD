
class Solution {
public:
    ListNode* f(ListNode* head, set<int> &st){
    if(! head) return NULL;
    head->next = f(head->next, st);
    if(st.count(head->val)){
        ListNode* next = head->next;
        delete(head);
        return next;
    }
    return head;
}

    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        set<int> st(nums.begin(), nums.end());
        return f(head, st);
    }
};
