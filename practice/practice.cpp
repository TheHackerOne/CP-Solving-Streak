class Solution
{
public:
  Node * removeDuplicates(Node *head) 
  {
    unordered_map<int, bool> mp;
    Node *dummy = new Node(-1), *curr = head;
    Node *prev = dummy;
    dummy->next = curr;
    while(curr){
      if(mp.find(curr->val) != mp.end()){
        curr = curr->next;
      }else{
        mp[curr->val] = true;
        prev->next = curr;
        prev = curr;
        curr = curr->next;
      }
    }
    prev->next = nullptr;
    return head;
  }
};