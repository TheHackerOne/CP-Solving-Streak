Node *insertHelper(Node *root, int &key) {
    // base case
    if (root == nullptr) {
        Node * newNode = new Node(key);
        return newNode;
    }

    // main logic
    if (root -> data == key) return root;
    if (root -> data > key) {
        root -> left = insertHelper(root->left, key);
    } else if (root -> data < key) {
        root -> right = insertHelper(root -> right, key);
    }
    return root;
}

Node* insert(Node* root, int Key) {
    if (root == nullptr) return root;
    return insertHelper(root, Key);
}