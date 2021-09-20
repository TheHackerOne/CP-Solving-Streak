vector<int> rightView(Node *root)
{
    vector<int> rv;
    if (root == nullptr) return rv;
    queue<Node *> q;
    q.push(root);
    while (!q.empty()) {
        int size = q.size();
        rv.push_back(q.front() -> data);
        while (size--) {
            Node *curr = q.front();
            q.pop();
            if (curr -> right != nullptr) {
                q.push(curr -> right);
            }
            if (curr -> left != nullptr) {
                q.push(curr -> left);
            }
        }
    }
    return rv;
}