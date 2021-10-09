#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode *slow = head, *fast = head;
        while (fast -> next != nullptr && fast -> next -> next != nullptr) {
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        if (fast -> next == nullptr) return slow ;
        else return slow -> next;
    }
};


int main() {


    return 0;
}