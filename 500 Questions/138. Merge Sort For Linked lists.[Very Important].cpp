class Solution {
public:
    //Function to sort the given linked list using Merge Sort.
    int lengthLL(Node *head) {
        int count = 0;
        Node *temp = head;
        while (temp != nullptr) {
            count++;
            temp = temp -> next;
        }
        return count;
    }

    Node *mid(Node *head) {
        Node *slow = head, *fast = head;
        while (fast -> next != nullptr && fast -> next -> next != nullptr) {
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        return slow;
    }

    Node *mergeLL(Node *h1, Node *h2) {
        Node *c1 = h1, *c2 = h2;
        Node *dummy = new Node(-1);
        Node *prev = dummy;
        while (c1 != nullptr && c2 != nullptr) {
            if (c1 -> data > c2 -> data) {
                prev -> next = c2;
                prev = c2;
                c2 = c2 -> next;
            } else {
                prev -> next = c1;
                prev = c1;
                c1 = c1 -> next;
            }
        }
        prev -> next = (c1 != nullptr ? c1 : c2);
        return dummy -> next;
    }

    Node *mergeSortHelper(Node *head) {
        Node *middle = mid(head);
        if (middle -> next == nullptr) return middle;
        Node *h1 = head, *h2 = middle -> next;
        middle -> next = nullptr;

        Node *x1 = mergeSortHelper(h1);
        Node *x2 = mergeSortHelper(h2);
        return mergeLL(x1, x2);
    }

    Node* mergeSort(Node* head) {
        return mergeSortHelper(head);
    }
};