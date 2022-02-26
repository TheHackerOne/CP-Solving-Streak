#include<bits/stdc++.h>
class Node{
private:
	Node* list[26];
	bool endsWith = false;

public:
	bool containsKey(char ch){
		return (list[ch-'a'] != nullptr);
	}

	void put(char ch, Node *node){
		list[ch-'a'] = node;
	}

	Node *get(char ch){
		return list[ch-'a'];
	}

	void setEnd(){
		endsWith = true;
	}

	bool EndsHere(){
		return endsWith;
	}
};

class Trie {
private:
	Node *root;
public:

	Trie() {
		root = new Node();
	}

	/** Inserts a word into the trie. */
	void insert(string word) {
		Node*node = root;
		for(int i=0;i<word.length();i++){
			if(!node->containsKey(word[i])){
				node->put(word[i], new Node());
			}
			node = node->get(word[i]);
		}
		node->setEnd();
	}

	/** Returns if the word is in the trie. */
	bool search(string word) {
		Node *node = root;
		for(int i=0;i<word.length();i++){
			if(!node->containsKey(word[i])){
				return false;
			}
			node = node->get(word[i]);
		}
		if(node->EndsHere())
			return true;
		else return false;
	}

	bool checkIfAllPrefixExists(string str){
		bool flag = true;
		Node *node = root;
		for(int i=0;i<str.length();i++){
			if(node->containsKey(str[i])){
				node = node->get(str[i]);
				if(!node->EndsHere()) {
					flag = false;
					break;
				}
			}else {
				flag = false;
				break;
			}
		}
		return flag;
	}
};


string completeString(int n, vector<string> &a){
    string ans = "";
    Trie trie;
    for(auto str:a){
    	trie.insert(str);
    }
    for(int i=0;i<a.size();i++){
        if(trie.checkIfAllPrefixExists(a[i])){
        		if(a[i].length() > ans.length()) {
        			ans = a[i];
        		}else if(a[i].length() == ans.length() and ans > a[i]){
        			ans = a[i];
        		}	
        }
    }
    if(ans.length() == 0) return "None";
    return ans;
}