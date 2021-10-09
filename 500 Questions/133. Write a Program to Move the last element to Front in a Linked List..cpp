#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    //Function to remove duplicates from unsorted linked list.
    void moveToFront(Node *head) {
        Node *temp = head, *prev = nullptr;
        while (temp -> next != nullptr) {
            prev = temp;
            temp = temp -> next;
        }
        prev -> next = nullptr;
        temp -> next = head;
        head = temp;
    }
};


int main() {


    return 0;
}