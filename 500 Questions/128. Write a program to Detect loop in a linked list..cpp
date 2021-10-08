// Method 1
class Solution
{
public:
    //Function to check if the linked list has a loop.
    bool detectLoop(Node* head)
    {
        unordered_map<Node*, int> mp;
        Node *temp = head;
        while (temp != nullptr) {
            if (mp.find(temp) != mp.end()) return true;
            mp[temp] = 1;
            temp = temp -> next;
        }
        return false;
    }
};

// Method 2
class Solution
{
public:
    //Function to check if the linked list has a loop.
    bool detectLoop(Node* head)
    {
        Node *slow = head, *fast = head;
        while (fast != nullptr && fast -> next != nullptr) {
            slow = slow -> next;
            fast = fast -> next -> next;
            if (slow == fast) return true;
        }
        return false;
    }
};