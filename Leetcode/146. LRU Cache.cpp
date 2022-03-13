class Node{
public:
   int key;
   int data;
   Node *prev;
   Node *next;

   Node(int key, int data){
      this->key = key;
      this->data = data;
      prev = next = nullptr;
   }
};

class LRUCache {
private:
   int size;
   Node *head;
   Node *tail;
   unordered_map<int, Node*> mp;
public:
    LRUCache(int capacity) {
      head = new Node(0, 0);
      tail = new Node(0, 0);
      head -> next = tail;
      tail -> prev = head;
      size = capacity;
    }
    
    int get(int key) {
        // if not present, return -1;
        if(mp.find(key) == mp.end()) return -1;

        // if present, make it most recently used and then update address of node in map too

        // remove node
        Node *node = mp[key];
        Node *prevNode = node -> prev;
        Node *nextNode = node -> next;
        prevNode -> next = nextNode;
        nextNode -> prev = prevNode;

        // add to most recently used
        Node *headNode = head;
        Node *headNext = head -> next;
        headNode -> next = node;
        node -> next = headNext;
        headNext -> prev = node;
        node -> prev = headNode;

        // return value
        return mp[key]->data;
    }
    
    void put(int key, int value) {
         // if key already present, update its value
        
         if(mp.find(key) != mp.end()){

            Node *node = mp[key];
            node -> data = value;

            // remove node
           Node *prevNode = node -> prev;
           Node *nextNode = node -> next;
           prevNode -> next = nextNode;
           nextNode -> prev = prevNode;

            // add to most recently used
            Node *headNode = head;
            Node *headNext = head -> next;
            headNode -> next = node;
            node -> next = headNext;
            headNext -> prev = node;
            node -> prev = headNode;
         }

         // if capacity is full, then remove LRU node and add new node

         else if(size == mp.size()){
            // remove lsu node
             
            Node *lru = tail -> prev;
            mp.erase(lru -> key);
            Node *prevNode = lru -> prev;
            Node *tailNode = tail;
            prevNode -> next = tailNode;
            tailNode -> prev = prevNode;

            // add new node
            Node *newNode = new Node(key, value);
            Node *headNode = head;
            Node *headNext = head -> next;
            headNode -> next = newNode;
            newNode -> next = headNext;
            headNext ->prev = newNode;
            newNode -> prev = headNode;

            mp[key] = newNode;
         }

         // if not full, simply add 

         else{
            // add new node
            Node *newNode = new Node(key, value);
            Node *headNode = head;
            Node *headNext = head -> next;
            headNode -> next = newNode;
            newNode -> next = headNext;
            headNext ->prev = newNode;
            newNode -> prev = headNode;

            mp[key] = newNode;
         }         

    }
};