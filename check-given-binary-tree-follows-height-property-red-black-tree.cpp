// http://www.geeksforgeeks.org/check-given-binary-tree-follows-height-property-red-black-tree/
#include <bits/stdc++.h>
using namespace std;

// struct node of binary tree
struct node{
	int data;
	node *left, *right;
};

// return new node 
node *getnode(int data){
	node *temp = new node();
	temp->data = data;
	temp->left = temp->right = NULL;
}

bool checkBalanced(node *root, int &maxh, int &minh){
	if(!root){
		maxh = minh = 0;
		return true;
	}
	int lmxh,lmnh, rmxh, rmnh;
	if(checkBalanced(root->left, lmxh,lmnh) == false) return false;
	if(checkBalanced(root->right, rmxh, rmnh) == false) return false;
	maxh = max(lmxh,rmxh) + 1;
	minh = min(lmnh,rmnh) + 1;
	if(maxh <= 2*minh) return true;
	return false;
}


int main(){
	//contruct binary tree
	node *root = getnode(1);
	root->left = getnode(2);
	root->left->left = getnode(4);
	// root->left->right = getnode(5);
	// root->left->left->right = getnode(2);
	// root->right = getnode(3);
	// root->right->right = getnode(8);
	// root->right->right->left = getnode(6);
	// root->right->right->right = getnode(7);

	// variable to store sum of right leaves
	int maxh, minh;
	if(checkBalanced(root, maxh, minh)) cout<< "yes\n";
	else cout << "no\n";
	return 0;
}