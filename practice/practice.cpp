
class Solution {
private:
    ListNode* reverseLL(ListNode *head){
        ListNode *prev = nullptr, *curr = head, *forw = nullptr;

        while(curr){
            forw = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = forw;
        }
        return prev;
    }
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *dummy = new ListNode(-1);
        dummy -> next = head;
        ListNode *curr = dummy;
        
        ListNode *first = curr, *second = curr, *third = curr, *fourth = curr;
        
        while(left--){
            first = second;
            second = second->next;
        }

        while(right--){
            third = third->next;
        }
        fourth = third->next;

        first->next = third->next = nullptr;
        third = reverseLL(second);

        first -> next = third;
        second -> next = fourth;

        return first->next;
    }
};