void iterativePrePostInTraversal(Node* node) {
  stack<pair<int, int>> st;
  vector<int> inorder, preorder, postorder;
  st.push({ node->val, 1 });
  while(!st.empty()){
    Node *node = st.top()->first;
    int stage = st.top()->second;
    if(stage == 1){
      preorder.push_back(node->val);
      st.top()->second += 1;
      if(node -> left != nullptr){
        st.push({ node->left, 1 });
      }
    }else if(stage == 2){
      inorder.push_back(node->val);
      st.top()->second += 1;
      if(node->right != nullptr){
        st.push({ node->right, 1 });
      }
    }else{
      postorder.push_back(node->val);
      st.pop();
    }
  }
}