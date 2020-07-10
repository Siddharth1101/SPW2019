// C++ implementation of search and insert 
// operations on Trie 
#include <bits/stdc++.h> 
using namespace std; 

const int ALPHABET_SIZE = 26; 
const int NUMBER_SIZE = 10; 



// trie node 
struct TrieNode 
{ 
	struct TrieNode *children[ALPHABET_SIZE]; 
	// isEndOfWord is true if the node represents 
	// end of a word 
	bool isEndOfWord; 
}; 
struct TrieNodeno 
{  
	struct TrieNode *children[NUMBER_SIZE]; 

	// isEndOfWord is true if the node represents 
	// end of a word 
	bool isEndOfnum; 
}; 

// Returns new trie node (initialized to NULLs) 
struct TrieNode *getNode(void) 
{ 
	struct TrieNode *pNode = new TrieNode; 

	pNode->isEndOfWord = false; 

	for (int i = 0; i < ALPHABET_SIZE; i++) 
		pNode->children[i] = NULL; 

	return pNode; 
} 
struct TrieNodeno *getNode(void) 
{ 
	struct TrieNodeno *pNode = new TrieNode; 

	pNode->isEndOfnum = false; 

	for (int i = 0; i < NUMBER_SIZE; i++) 
		pNode->children[i] = NULL; 

	return pNode; 
}

// If not present, inserts key into trie 
// If the key is prefix of trie node, just 
// marks leaf node 
void insert(struct TrieNode *root, string key) 
{ 
	struct TrieNode *pCrawl = root; 

	for (int i = 0; i < key.length(); i++) 
	{ 
		int index = key[i] - 'a'; 
		if (!pCrawl->children[index]) 
			pCrawl->children[index] = getNode(); 

		pCrawl = pCrawl->children[index]; 
	} 

	// mark last node as leaf 
	pCrawl->isEndOfWord = true; 
} 
void insert(struct TrieNodeno *root, string num) 
{ 
	struct TrieNodeno *pCrawl = root; 

	for (int i = 0; i < num.length(); i++) 
	{ 
		int index = key[i] - '0'; 
		if (!pCrawl->children[index]) 
			pCrawl->children[index] = getNode(); 

		pCrawl = pCrawl->children[index]; 
	} 

	// mark last node as leaf 
	pCrawl->isEndOfnum = true; 
} 

// Returns true if key presents in trie, else 
// false 
bool search(struct TrieNode *root, string key) 
{ 
	struct TrieNode *pCrawl = root; 
	 transform(key.begin(), key.end(), key.begin(), ::tolower); 
	for (int i = 0; i < key.length(); i++) 
	{ 
		int index = key[i] - 'a'; 
		if (!pCrawl->children[index]) 
			return false; 

		pCrawl = pCrawl->children[index]; 
	} 

	return (pCrawl != NULL && pCrawl->isEndOfWord); 
} 
bool search(struct TrieNodeno *root, string num) 
{ 
	struct TrieNodeno *pCrawl = root; 
	 
	for (int i = 0; i < num.length(); i++) 
	{ 
		int index = key[i] - '0'; 
		if (!pCrawl->children[index]) 
			return false; 

		pCrawl = pCrawl->children[index]; 
	} 

	return (pCrawl != NULL && pCrawl->isEndOfnum); 
} 

void add(string key, string num){
	n=key.length();
	m=num.length();
	for (int i = 0; i < n; i++) 
		insert(root, keys[i]); 
for (int i = 0; i < m; i++) 
		insert(root, num[i]); 

}
// Driver 
int main() 
{ 
	// Input keys (use only 'a' through 'z' 
	// and lower case) 
	string str;
	cout<<"Enter the search word (lowercase or uppercase) ";
	cin>>str;
	string keys[] = {("the","8904")}
					// "a", "there", 
					//"answer", "any", "by", 
					//"bye", "their" }; 
	int n = sizeof(keys)/sizeof(keys[0]); 
		struct TrieNode *root = getNode(); 

	// Construct trie 
	for (int i = 0; i < n; i++) 
		insert(root, keys[i]); 

	

	// Search for different keys 
	search(root, str)? cout << "\nPresent\n" : 
						cout << "\nNot present\n"; 
					
	return 0; 
} 
