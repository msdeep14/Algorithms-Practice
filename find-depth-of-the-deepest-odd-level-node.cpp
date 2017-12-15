//http://www.geeksforgeeks.org/find-depth-of-the-deepest-odd-level-node/
#include <bits/stdc++.h>
using namespace std;
struct node{
	int data;
	node *left;
	node *right;
};

node *getnode(int data){
	node *temp = new node();
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
}

int findMaxDepth(node *root, int level){
	if(!root) return 0;
	if(!root->left && !root->right && level&1)
		return level;
	return max(findMaxDepth(root->left, level+1),findMaxDepth(root->right, level+1));
}

int main(){
	node *root = getnode(1);
	root->left = getnode(2);
	root->right = getnode(3);
	root->left->left = getnode(6);
	root->left->right = getnode(5);
	int level = findMaxDepth(root,1);
	cout << "max odd depth :: " << level << endl;
	return 0;
}