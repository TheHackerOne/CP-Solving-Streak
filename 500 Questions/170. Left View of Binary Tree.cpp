vector<int> leftView(Node *root)
{
    vector<int> leftV;
    if (root == NULL) return leftV;
    queue<Node *> q;
    q.push(root);
    while (!q.empty()) {
        int size = q.size();
        leftV.push_back(q.front() -> data);
        while (size--) {
            Node *curr = q.front();
            q.pop();
            if (curr -> left != NULL) {
                q.push(curr -> left);
            }
            if (curr -> right != NULL) {
                q.push(curr -> right);
            }
        }
    }
    return leftV;
}
