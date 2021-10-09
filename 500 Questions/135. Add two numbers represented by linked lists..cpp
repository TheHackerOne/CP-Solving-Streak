class Solution
{
public:
    //Function to add two numbers represented by linked list.
    // struct Node* addTwoLists(struct Node* first, struct Node* second)
    // {
    //     // code here
    // }

    int lengthLL(Node *head) {
        int count = 0;
        Node *temp = head;
        while (temp != nullptr) {
            temp = temp -> next;
            count++;
        }
        return count;
    }

    Node *reverseLL(Node *head) {
        Node *prev = nullptr, *curr = head, *forw = nullptr;
        while (curr != nullptr) {
            forw = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = forw;
        }
        return prev;
    }

    Node *addTwoLists(Node *h1, Node *h2) {
        int l1 = lengthLL(h1);
        int l2 = lengthLL(h2);
        Node *newh1, *newh2;
        if (l1 > l2) {
            newh1 = reverseLL(h1);
            newh2 = reverseLL(h2);
        } else {
            newh1 = reverseLL(h2);
            newh2 = reverseLL(h1);
        }

        Node *curr1 = newh1, *curr2 = newh2;
        int carry = 0;
        while (curr1 != nullptr && curr2 != nullptr) {
            int currSum = curr1 -> data + curr2 -> data + carry;
            if (currSum > 9) {
                int remNum = currSum % 10;
                carry = 1;
                curr1 -> data = remNum;
            } else {
                carry = 0;
                curr1 -> data = currSum;
            }
            curr1 = curr1 -> next;
            curr2 = curr2 -> next;
        }
        if (curr1 == nullptr) {
            if (carry > 0) {
                Node *newNode = new Node(carry);
                Node *h = reverseLL(newh1);
                newNode -> next = h;
                return newNode;
            } else {
                return reverseLL(newh1);
            }
        } else {
            while (curr1 != nullptr) {
                int currSum = curr1 -> data + carry;
                if (currSum > 9) {
                    carry = currSum / 10;
                    curr1 -> data = currSum % 10;
                } else {
                    carry = 0;
                    curr1 -> data = currSum;
                }
                curr1 = curr1 -> next;
            }
            Node *newNode = nullptr;
            if (carry > 0) {
                newNode = new Node(carry);
                Node *hn = reverseLL(newh1);
                newNode -> next = hn;
                return newNode;
            }
            return reverseLL(newh1);
        }
    }
};