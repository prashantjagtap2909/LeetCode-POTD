class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode* prev=head->next, *curr=head->next, *tmp=head;
        delete tmp;/
        ListNode ans(0, curr);
        int sum=0;
        for (; curr; curr=curr->next, delete tmp){ 
            int x=curr->val;
            if (x!=0) {
                sum+=x;
                tmp=(prev==curr)?NULL:curr;
            }
            else{
                tmp=curr;
                prev->val=sum;
                prev->next=curr->next;
                prev=prev->next;
                sum=0;
            }
        } 
        return ans.next;
    }
};
