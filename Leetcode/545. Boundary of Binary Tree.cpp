
bool leafNode(TreeNode<int> *root){
	if(root -> left or root -> right) return false;
	return true;
}

void getLeft(TreeNode<int> *root, vector<int> &res){
	TreeNode<int>* curr = root->left;
	while(curr){
		if(!leafNode(curr)) res.push_back(curr->data);
		if(curr->left) curr = curr -> left;
		else curr = curr->right;
	}
}

void inorder(TreeNode<int> *root, vector<int> &res){
	if(root == nullptr) return;

	inorder(root->left, res);
	if(leafNode(root)) res.push_back(root->data);
	inorder(root->right, res);
}

void getRight(TreeNode<int> *root, vector<int> &res){
	vector<int> temp;
	TreeNode<int> *curr = root->right;
	while(curr){
		if(!leafNode(curr)) temp.push_back(curr->data);
		if(curr -> right) curr = curr -> right;
		else curr = curr -> left;
	}
	for(int i=temp.size()-1;i>=0;i--){
		res.push_back(temp[i]);
	}
}
vector<int> traverseBoundary(TreeNode<int>* root){
	vector<int> res;
	if(!root) return res;
	if(!leafNode(root)) res.push_back(root->data);

        // get left part of tree
	getLeft(root, res);
        // all leaf nodes, that i'll get from inorder traversal of tree
	inorder(root, res);
        // get right part of tree
	getRight(root, res);

	return res;
}