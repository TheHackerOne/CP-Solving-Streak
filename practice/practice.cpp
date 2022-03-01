#include <iostream>
#include <vector>
#include <stack>
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
  int val;
  vector<Node*> children;

  Node() {}

  Node(int _val)
  {
    val = _val;
  }

  Node(int _val, vector<Node*> _children)
  {
    val = _val;
    children = _children;
  }
};

void preorder(Node *root, string &str){

  str += to_string(root->val)+" ";
  for(auto child:root->children){
    preorder(child, str);
  }
  str += "-1 ";
}

// Encodes a tree to a single string.
string serialize(Node* root)
{
  if(root == nullptr) return "";
  string str = "";
  preorder(root, str);
  return str;
}

vector<int> simple_tokenizer(string s)
{
  vector<int> ans;
  stringstream ss(s);
  string word;
  while (ss >> word) {
      ans.push_back(stoi(word));
  }
  return ans;
}



// Decodes your encoded data to tree.
Node* deserialize(string s){
  vector<int> split = simple_tokenizer(s);
  Node *root = new Node(split[0]);
  stack<Node *> st;
  st.push(root);
  for(int i=1;i<split.size();i++){
    if(split[i] != -1){
      Node *newNode = new Node(split[i]);
      st.push(newNode);
    }else{
      Node *top = st.top();
      st.pop();
      st.top() -> children.push_back(top);
    }
  }
  return root;  
}

// input_Section_====================================================================

void display(Node* node)
{
  if (node == nullptr)
    return;

  string str = node->val + "->";
  for (Node* child : node->children)
  {
    str += child->val;
  }

  for (Node* child : node->children)
  {
    display(child);
  }
}

Node* createTree(vector<string>& arr)
{
  stack<Node*> st;
  for (int i = 0; i < arr.size - 1; i++)
  {
    string s = arr[i];
    if (s == "null")
    {
      Node* node = st.top();
      st.pop();
      st.peek()->children.add(node);
    }
    else
    {
      Node* node = new Node(stoi(s));
      st.push(node);
    }
  }

  return st.size() != 0 ? st.top() : nullptr;
}

void solve()
{
  string str;
  cin >> str;
  stringstream ss(str);
  string word;
  vector<string> arr;
  while (ss >> word)
    arr.push_back(word);

  Node* root = createTree(arr);
  string s = serialize(root);
  display(deserialize(s));
}

int main()
{
  solve();
  return 0;
}