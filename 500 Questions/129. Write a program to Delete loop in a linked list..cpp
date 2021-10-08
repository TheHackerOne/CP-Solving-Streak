class Solution
{
public:
    //Function to remove a loop in the linked list.
    void detectLoop(Node *head) {
        Node *slow = head, *fast = head;
        Node *temp = nullptr;
        while (fast != nullptr && fast -> next != nullptr) {
            temp = slow;
            slow = slow -> next;
            fast = fast -> next -> next;

            if (slow == fast) {
                break;
            }
        }
        if (fast == nullptr || fast -> next == nullptr) return;
        slow = head;
        while (slow != fast) {
            slow = slow -> next;
            temp = fast;
            fast = fast -> next;
        }
        temp -> next = nullptr;
    }

    void removeLoop(Node* head) {
        detectLoop(head);
    }
};