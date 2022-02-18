

bool rootToNodePath(BinaryTreeNode<int> *root, int node, vector<BinaryTreeNode<int>*> &res){
    // base case
    if(root == nullptr) return false;

    // main logic
    if(root->data == node){
        res.push_back(root);
        return true;
    }

    bool left = rootToNodePath(root->left, node, res);
    bool right = rootToNodePath(root->right, node, res);
    if(left or right){
        res.push_back(root);
        return true;
    }
    return left or right;
}


BinaryTreeNode<int>* lcaOfThreeNodes(BinaryTreeNode<int>* root, int node1, int node2, int node3) {
    vector<BinaryTreeNode<int>*> rtnp1;
    rootToNodePath(root, node1, rtnp1);    

    vector<BinaryTreeNode<int>*> rtnp2;
    rootToNodePath(root, node2, rtnp2);    

    vector<BinaryTreeNode<int>*> rtnp3;
    rootToNodePath(root, node3, rtnp3);   

    if(node1 == node2 and node2 == node3) return rtnp3[0];

    int first = rtnp1.size()-1, second = rtnp2.size()-1, third = rtnp3.size()-1;
    while(rtnp1[first] == rtnp2[second] and rtnp2[second] == rtnp3[third]){
        first--, second--, third--;
    }

    return rtnp2[second+1];

}