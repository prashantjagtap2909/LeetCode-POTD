class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int N) {
        int cnt = 0;
        ListNode *temp = head;
        while(temp){
            cnt++;
            temp = temp->next;

        };
        cnt -= N;
        if(cnt == 0){
            temp = head;
            head = head->next;
            delete temp;

            return head;
        }
        ListNode *curr = head, *prev = NULL;
        while(cnt--){
            prev = curr;
            curr = curr->next;
        };
        prev->next = curr->next;
        delete curr;


        return head;
    }
};
