vector<int> levelOrder(Node* node)
{
    queue<Node *> q;
    vector<int> ans;
    q.push(node);
    ans.push_back(node->data);
    while (!q.empty()) {
        Node *node = q.front();
        q.pop();
        if (node -> left != nullptr) {
            q.push(node -> left);
            ans.push_back(node -> left -> data);
        }
        if (node -> right != nullptr) {
            q.push(node -> right);
            ans.push_back(node -> right -> data);
        }
    }
    return ans;
}