#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    //Function to check whether the list is palindrome.
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

    Node *midEle(Node *head) {
        Node *slow = head, *fast = head;
        while (fast -> next != nullptr && fast -> next -> next != nullptr) {
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        if (fast -> next == nullptr) return slow;
        else return slow -> next;
    }

    bool isPalindrome(Node *head)
    {
        Node *mid = midEle(head);
        Node *h1 = head, *h2 = reverseLL(mid);
        while (h1 != nullptr && h2 != nullptr) {
            if (h1 -> data != h2 -> data) return false;
            h1 = h1 -> next;
            h2 = h2 -> next;
        }
        return true;
    }
};

int main() {


    return 0;
}