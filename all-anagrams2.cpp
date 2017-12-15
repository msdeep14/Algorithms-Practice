// all anagrams approach 2 using trie
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

// Trienode
struct node{
	struct node *child[26];
	bool isleaf;
	vector<int> list;
};

// utility function for creating new Trienode
node* getnode(){
	node* pnode = new node();
	for(int i=0;i<26;i++){
		pnode->child[i] = NULL;
	}
	pnode->isleaf = false;
}

// utility function for inserting a string
// into trie
void insert(node *root, string s, int sindex){
	int len = s.length();
	node *pnode = root;
	for(int i=0;i<len;i++){
		int index = s[i]-97;
		if(!pnode->child[index]){
			pnode->child[index] = getnode();
		}
		pnode = pnode->child[index];
	}
	pnode->isleaf = true;
	pnode->list.push_back(sindex);
}

// utility function for traversing the trie
// and printing the anagrams
void traverse(node *root,vector<string> &arr){
	if(root == NULL) return;
    // traverse till the last and print the list
    // only if size > 1
    // because atleast 2 anagrams
	if(root->isleaf && root->list.size() > 1){
		for(int j = 0; j < root->list.size(); j++){
			cout << arr[root->list[j]] << " ";
		}
        cout << "\n";
	}
	for(int i=0;i<26;i++){
		traverse(root->child[i],arr);
	}
}

int main(){
    // initialize root node
	node * root = getnode();
	vector<string> arr;
    arr.push_back("geeksquiz");
    arr.push_back("geeksforgeeks");
    arr.push_back("abcd");
    arr.push_back("forgeeksgeeks");
    arr.push_back("zuiqkeegs");
    arr.push_back("cat");
    arr.push_back("act");
    arr.push_back("tca");

    // insert vector elements into trie
	for(int i = 0; i < arr.size(); i++){
        string tempString(arr[i]);
		sort(tempString.begin(),tempString.end());
		insert(root,tempString,i);
	}

    // traverse the created trie
	traverse(root,arr);
    return 0;
}
