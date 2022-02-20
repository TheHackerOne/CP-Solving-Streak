

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *curr1 = l1, *curr2 = l2;
        int carry = 0;
        ListNode *dummy = new ListNode(-1);
        ListNode *prev = dummy;
        while(curr1 != nullptr or curr2 != nullptr){
            int sum = (curr1 != nullptr ? curr1->val : 0) + (curr2 != nullptr ? curr2->val : 0) + carry;
            if(sum <= 9){
                carry = 0;                
            }else{
                carry = sum/10;
                sum = sum%10;
            }
            ListNode* newNode = new ListNode(sum);
            prev -> next = newNode;
            prev = newNode;
            if(curr1 != nullptr)
                curr1 = curr1 -> next;
            if(curr2 != nullptr)
                curr2 = curr2 -> next;
        }
        if(carry){
            ListNode *newNode = new ListNode(carry);
            prev -> next = newNode;
            prev = newNode;
        }

        return dummy -> next;
    }
};