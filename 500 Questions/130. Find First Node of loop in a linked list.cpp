class Solution
{
public:
    //Function to remove a loop in the linked list.
    Node *detectLoop(Node *head) {
        Node *slow = head, *fast = head;
        while (fast != nullptr && fast -> next != nullptr) {
            slow = slow -> next;
            fast = fast -> next -> next;

            if (slow == fast) {
                break;
            }
        }
        if (fast == nullptr || fast -> next == nullptr) return nullptr;
        slow = head;
        while (slow != fast) {
            slow = slow -> next;
            fast = fast -> next;
        }
        return slow;
    }

    Node *firstNodeofLoop(Node* head) {
        return detectLoop(head);
    }
};