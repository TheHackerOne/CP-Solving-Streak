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

	/** Returns if there is any word in the trie that starts with the given prefix. */
	bool startsWith(string prefix) {
		Node *node = root;
		for(int i=0;i<prefix.length();i++){
			if(!node->containsKey(prefix[i])){
				return false;
			}
			node = node->get(prefix[i]);
		}
		return true;
	}
};
