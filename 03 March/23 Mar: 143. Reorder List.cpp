
class Solution {
public:
     ListNode* reverse(ListNode *head){
        if(!head) return NULL;
        ListNode *prev = NULL;
        ListNode *curr = head;
        ListNode *nextNode = NULL;
        while(curr){
            nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev;
    }

    void merge(ListNode *list1, ListNode *list2){
        while(list2) {
            ListNode  *nextNode = list1->next;
            list1->next = list2;
            list1 = list2;
            list2 = nextNode;

        }

    }
    void reorderList(ListNode* head) {
        if(!head || !head->next) return;
        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *prev = head;
        while(fast && fast->next){
            prev = slow;
            fast = fast->next->next;
            slow = slow->next;
        }
        prev->next = NULL;
        ListNode *list1 = head;
        ListNode *list2 = reverse(slow);
        merge(list1,list2);
    }
};
