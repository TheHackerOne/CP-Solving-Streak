#include <iostream>
using namespace std;

class ListNode
{
public:
    int val = 0;
    ListNode *next = nullptr;

    ListNode(int val)
    {
        this->val = val;
    }
};

void printList(ListNode *node)
{
    ListNode *curr = node;
    while (curr != nullptr)
    {
        cout << curr->val << " ";
        curr = curr->next;
    }
    cout << endl;
}

ListNode *segregate012(ListNode *head){
    ListNode *zero = new ListNode(-1), *one = new ListNode(-1), *two = new ListNode(-1);
    ListNode *pervZero = zero, *prevOne = one, *prevTwo = two;
    ListNode *curr = head;
    while(curr != nullptr){
        if(curr->val == 0){
            pervZero->next = curr;
            pervZero = curr;
        }else if(curr->val == 1){
            prevOne->next = curr;
            prevOne = curr;
        }else{
            prevTwo->next = curr;
            prevTwo = curr;
        }
        curr = curr -> next;
    }
    pervZero->next = prevOne->next = prevTwo->next = nullptr;
    // printList(zero->next);
    // printList(one->next);
    // printList(two->next);
    prevOne->next = two->next;
    pervZero->next = one->next;
    return zero->next;
}



ListNode *createList(int n)
{
    ListNode *dummy = new ListNode(-1);
    ListNode *prev = dummy;
    while (n-- > 0)
    {
        int val;
        cin >> val;
        prev->next = new ListNode(val);
        prev = prev->next;
    }
    return dummy->next;
}

int main()
{
    int n;
    cin >> n;
    ListNode *h1 = createList(n);
    h1 = segregate012(h1);
    printList(h1);

    return 0;
}