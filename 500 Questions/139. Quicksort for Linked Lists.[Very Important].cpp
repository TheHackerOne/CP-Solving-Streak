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
ListNode * *segregate(ListNode *head, int pivotIdx) {
    ListNode *small = new ListNode(-1);
    ListNode *large = new ListNode(-1);
    ListNode *curr = head, *ps = small, *pl = large;
    ListNode *pivotEle = head;
    while ( pivotIdx -- ) {
        pivotEle = pivotEle -> next;
    }
    while (curr != nullptr) {
        if (curr != pivotEle) {
            if (curr -> val > pivotEle -> val) {
                pl -> next = curr;
                pl = curr;
            } else {
                ps -> next = curr;
                ps = curr;
            }
        }
        curr = curr -> next;
    }
    pl -> next = nullptr;
    ps -> next = nullptr;
    pivotEle -> next = nullptr;
    ListNode * *ans = new ListNode*[3];
    ans[0] = small -> next;
    ans[1] = pivotEle;
    ans[2] = large -> next;
    return ans;
}

int lengthLL(ListNode *head) {
    int count = 0;
    ListNode *temp = head;
    while (temp != nullptr) {
        count++;
        temp = temp -> next;
    }
    return count;
}

ListNode * *mergeLL(ListNode **headTailsmall, ListNode **headTaillarge, ListNode *pivotEle) {
    ListNode **ans = new ListNode*[2];
    if (headTailsmall[0] == nullptr && headTaillarge[0] == nullptr) {
        ans[0] = pivotEle;
        ans[1] = pivotEle;
    } else if (headTailsmall[0] == nullptr) {
        pivotEle -> next = headTaillarge[0];
        ans[0] = pivotEle;
        ans[1] = headTaillarge[1];
    } else if (headTaillarge[0] == nullptr) {
        headTailsmall[1] -> next = pivotEle;
        ans[0] = headTailsmall[0];
        ans[1] = pivotEle;
    } else {
        headTailsmall[1] -> next = pivotEle;
        pivotEle -> next = headTaillarge[0];
        ans[0] = headTailsmall[0];
        ans[1] = headTaillarge[1];
    }
    return ans;
}

ListNode * *quickSort_(ListNode *head) {
    // segregate LL in two lists and one pivotEle
    if (head == nullptr || head -> next == nullptr) {
        ListNode * *newListNode = new ListNode*[2];
        newListNode[0] = head;
        newListNode[1] = head;
        return newListNode;
    }
    int pivotIdx = lengthLL(head) / 2;
    ListNode * *ans = segregate(head, pivotIdx);
    ListNode *LLsmall = ans[0];
    ListNode *LLlarge = ans[2];
    ListNode *pivotEle = ans[1];
    int lenSmall = lengthLL(LLsmall);
    int lenLarge = lengthLL(LLlarge);
    ListNode * *headTailsmall = quickSort_(LLsmall);
    ListNode * *headTaillarge = quickSort_(LLlarge);
    return mergeLL(headTailsmall, headTaillarge, pivotEle);
}

ListNode *quickSort(ListNode *head)
{
    return quickSort_(head)[0];
}

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

    ListNode *head = quickSort(h1);
    printList(head);

    return 0;
}