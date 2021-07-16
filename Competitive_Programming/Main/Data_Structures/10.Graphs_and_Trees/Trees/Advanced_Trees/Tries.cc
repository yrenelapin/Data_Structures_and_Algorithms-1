#include <bits/stdc++.h>
using namespace std;

const int ALPHABET_SIZE = 26;

struct TrieNode {
	struct TrieNode* children[ALPHABET_SIZE];
	bool isEndOfWord;
};

// Returns new trie node (initialized to NULLs)
struct TrieNode* getNode(void){
	struct TrieNode* pNode = new TrieNode;
	pNode->isEndOfWord = false;
	for (int i = 0; i < ALPHABET_SIZE; i++)
		pNode->children[i] = NULL;
	return pNode;
}

// If not present, inserts key into trie. If the key is prefix of trie node, just marks leaf node.
// O(p),  p = key.size()
void insert(struct TrieNode* root, string key){
	struct TrieNode* trackPointer = root;
	for (int i = 0; i < key.length(); i++) {
		int index = key[i] - 'a';
		if (!trackPointer->children[index])
			trackPointer->children[index] = getNode();
		trackPointer = trackPointer->children[index];
	}
	trackPointer->isEndOfWord = true;
}

// Returns true if key is present in trie.
// O(p),  p = key.size()
bool search(struct TrieNode* root, string key){
	struct TrieNode* trackPointer = root;
	for (int i = 0; i < key.length(); i++) {
		int index = key[i] - 'a';
		if (!trackPointer->children[index])
			return false;
		trackPointer = trackPointer->children[index];
	}
	return (trackPointer != NULL && trackPointer->isEndOfWord);
}

// Returns true if there is word(key) that starts with `key` among the previously inserted words.
// O(p),  p = key.size()
bool startsWith(struct TrieNode* root, string key){
	struct TrieNode* trackPointer = root;
	for (int i = 0; i < key.length(); i++) {
		int index = key[i] - 'a';
		if (!trackPointer->children[index])
			return false;
		trackPointer = trackPointer->children[index];
	}
	return (trackPointer != NULL);
}

// Returns true if root has no children, else false
bool isEmpty(TrieNode* root){
	for (int i = 0; i < ALPHABET_SIZE; i++)
		if (root->children[i])
			return false;
	return true;
}

// Recursive function to delete a key from given Trie
// O(p),  p = key.size()
TrieNode* remove(TrieNode* root, string key, int depth = 0){

	// If tree is empty
	if (!root)
		return NULL;

	// If last character of key is being processed
	if (depth == key.size()) {

		// This node is no more end of word after removal of given key
		if (root->isEndOfWord)
			root->isEndOfWord = false;

		// If given is not prefix of any other word
		if (isEmpty(root)) {
			delete (root);
			root = NULL;
		}

		return root;
	}

	// If not last character, recur for the child obtained using ASCII value
	int index = key[depth] - 'a';
	root->children[index] = remove(root->children[index], key, depth + 1);

	// If root does not have any child (its only child got deleted), and it is not end of another word.
	if (isEmpty(root) && root->isEndOfWord == false) {
		delete (root);
		root = NULL;
	}

	return root;
}

int main(){
     // Input keys should contain only 'a' through 'z' and lower case.
     // For other Inputs modify the code/input accordingly.
     struct TrieNode* root = getNode();
     int n; cin >> n; char operation; string key;
     for(int i = 0; i <n ; i++){
         cin >> operation >> key;
         if (operation == 'i'){
            insert(root, key);
         }
         else if (operation == 's'){
            search(root, key) ? cout << "YES " : cout << "NO ";
         }
         else if (operation == 'w'){
             startsWith(root, key) ? cout << "YES " : cout << "NO ";
         }
         else if (operation == 'd') {
             remove(root, key);
         }
     }
	return 0;
}