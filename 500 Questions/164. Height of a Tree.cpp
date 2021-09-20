int heightTree(struct Node* node) {
    if (node == nullptr) return 0;
    int left = heightTree(node -> left);
    int right = heightTree(node -> right);
    return max(left, right) + 1;
}

int height(struct Node* node) {
    return heightTree(node);
}