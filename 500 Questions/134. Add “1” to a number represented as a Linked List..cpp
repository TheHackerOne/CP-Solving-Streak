class Solution
{
public:

    Node *reverse(Node *head) {
        Node *prev = nullptr, *curr = head, *forw = nullptr;
        while (curr != nullptr) {
            forw = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = forw;
        }
        return prev;
    }


    Node* addOne(Node *head)
    {
        Node *revHead = reverse(head);
        Node *temp = revHead;
        int firstNum = temp -> data + 1;
        int carry = 0;
        if (firstNum > 9) {
            temp -> data = 0;
            carry = 1;
        } else {
            temp -> data += 1;
            return reverse(revHead);
        }
        temp = temp -> next;
        while (temp != nullptr) {
            int currNum = temp -> data + carry;
            if (currNum > 9) {
                carry = 1;
                temp -> data = 0;
            } else {
                carry = 0;
                temp -> data = currNum;
            }
            temp = temp -> next;
        }

        Node *newNode = new Node(1);
        if (carry == 1) {
            Node *tHead = reverse(revHead);
            newNode -> next = tHead;
            return newNode;
        } else {
            return reverse(revHead);
        }
    }
};