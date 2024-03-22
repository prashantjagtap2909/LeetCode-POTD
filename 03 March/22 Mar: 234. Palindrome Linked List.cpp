class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(head->next == NULL) return 1;
        int cnt = 0;
        ListNode *temp = head;
        while(temp){
            cnt++;
            temp = temp->next;
        };
        cnt /= 2;
        ListNode *curr = head , *prev = NULL;
        while(cnt--){
            prev = curr;
            curr = curr->next;
        };
        prev->next = NULL;

        ListNode *front;
        prev = NULL;
        while(curr){
            front = curr->next;
            curr->next = prev;
            prev = curr;
            curr = front;
        };

        ListNode *head1 = head, *head2 = prev;

        while(head1){
            if(head1->val != head2->val)
                return 0;
                head1 = head1->next;
                head2 = head2->next;
            
        }
        return 1;
    }
};
