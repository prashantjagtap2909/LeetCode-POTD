class Solution {
public:
    ListNode* doubleIt(ListNode* head) {
        stack<int> values;
        int val = 0;
        while (head != nullptr) {
            values.push(head->val);
            head = head->next;
        }

        ListNode* newTail = nullptr;
         while (!values.empty() || val != 0) {
            newTail = new ListNode(0, newTail);
            if (!values.empty()) {
                val += values.top() * 2;
                values.pop();
            }
            newTail->val = val % 10;
            val /= 10;
        }
        return newTail;
    }
};
