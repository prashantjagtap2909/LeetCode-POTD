
class Solution {
public:
    int GCD(int a,int b){
        int minn=min(a,b);
        for(int i=minn;i>=1;i--){
            if(a%i==0 && b%i==0) return i;
        }
        return 1;
    }
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(head->next==NULL) return head;
        ListNode* ans=head;
        while(head->next){
            int x=GCD(head->val,head->next->val);
            ListNode* temp=new ListNode(x);
            temp->next=head->next;
            head->next=temp;
            head=temp->next;
        }
        return ans;
    }
};
