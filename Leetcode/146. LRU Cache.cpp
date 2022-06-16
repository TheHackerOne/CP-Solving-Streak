

class LRUCache {
private:
    class Node{
        public:
        int key;
        int value;
        Node *prev = nullptr;
        Node *next = nullptr;
        
        Node(int key, int val){
            this->key = key;
            this->value = val;
        }
    };
    
    unordered_map<int, Node*> mp; // key --> LL Node address
    Node *head = nullptr, *tail = nullptr;
    int size = 0, cap = 0;
    
    void removeNode(Node *node){
        Node *nodePrev = node->prev;
        Node *nodeNext = node->next;
        nodePrev->next = nodeNext;
        nodeNext->prev = nodePrev;
    }
    
    void addToMostRecent(Node *node){
        Node *headNode = head;
        Node *headNext = head->next;
        headNode->next = node;
        node->next = headNext;
        headNext->prev = node;
        node->prev = headNode;
    }
    
public:
    LRUCache(int capacity) {
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
        cap = capacity;
    }
    
    int get(int key) {
        if(mp.find(key) != mp.end()){
            Node *node = mp[key];
            removeNode(node);
            addToMostRecent(node);
            return node->value;
        }else{
            return -1;
        }
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()){
            Node *node = mp[key];
            node->value = value;
            removeNode(node);
            addToMostRecent(node);
        }else{
            Node *newNode = new Node(key, value);
            if(size == cap){
                Node *leastUsedNode = tail->prev;
                removeNode(leastUsedNode);
                mp.erase(leastUsedNode->key);
                addToMostRecent(newNode);
                mp[key] = newNode;
            }else{
                addToMostRecent(newNode);
                mp[key] = newNode;
                size++;
            }
        }
    }
};
