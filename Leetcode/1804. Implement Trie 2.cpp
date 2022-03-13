class Node{
public:
	Node* list[26];
	int endsWith = 0;
	int countPrefix = 0;

	bool containsKey(char ch){
		return (list[ch-'a'] != nullptr);
	}

	void put(char ch, Node *node){
		list[ch-'a'] = node;
	}

	Node *get(char ch){
		return list[ch - 'a'];
	}

	void incrementPrefix(){
		countPrefix += 1;
	}

	void EndsHere(){
		endsWith += 1;
	}

	int endsWithCount(){
		return endsWith;
	}

	int getPrefixCount(){
		return countPrefix;
	}

	void decrementPrefix(){
		countPrefix--;
	}

	void decrementEndsCount(){
		endsWith--;
	}
};

class Trie{
private:
	Node *root;
public:

	Trie(){
		root = new Node();
	}

	void insert(string &word){
	  Node *node = root;
	  for(int i=0;i<word.length();i++){
	  		if(!node->containsKey(word[i])){
	  			node->put(word[i], new Node());
	  		}
	  		node = node->get(word[i]);
	  		node->incrementPrefix();
	  }
	  node->EndsHere();
	}

	int countWordsEqualTo(string &word){
	  Node *node = root;
	  for(int i=0;i<word.length();i++){
	  		if(!node->containsKey(word[i])){
	  			node->put(word[i], new Node());
	  		}
	  		node = node->get(word[i]);
	  }
	  return node->endsWithCount();
	}

	int countWordsStartingWith(string &word){
	  Node *node = root;
	  for(int i=0;i<word.length();i++){
	  		if(!node->containsKey(word[i])){
	  			node->put(word[i], new Node());
	  		}
	  		node = node->get(word[i]);
	  }
	  return node->getPrefixCount();
	}

	void erase(string &word){
	 	Node *node = root;
		for(int i=0;i<word.length();i++){
			if(!node->containsKey(word[i])){
				return;
			}
			node = node->get(word[i]);
			node->decrementPrefix();
		}
		node->decrementEndsCount();
	}
};
