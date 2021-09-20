vector<int> reverseLevelOrder(Node *root)
{
    queue<Node *> q;
    q.push(root);
    vector<int> ans;
    ans.push_back(root -> data);
    while (!q.empty()) {
        Node *node = q.front();
        q.pop();
        if (node -> right != nullptr) {
            q.push(node -> right);
            ans.push_back(node -> right -> data);
        }
        if (node -> left != nullptr) {
            q.push(node -> left);
            ans.push_back(node -> left -> data);
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}