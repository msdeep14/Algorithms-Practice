// CPP program to find sum of
// all leaf nodes of binary tree
#include <bits/stdc++.h>
using namespace std;

// struct binary tree node
struct node{
	int data;
	node *left, *right;
};

// return new node 
node *newnode(int data){
	node *temp = new node();
	temp->data = data;
	temp->left = temp->right = NULL;
}

// utility function which calculates
// sum of all leaf nodes
void leafSum(node *root, int *sum){
	if(!root)
		return;

	// add root data to sum if 
	// root is a leaf node
	if(!root->left && !root->right)
		*sum += root->data;

	// propagate recursively in left
	// and right subtree
	leafSum(root->left, sum);
	leafSum(root->right, sum);
}

// driver program
int main(){
	//contruct binary tree
	node *root = newnode(1);
	root->left = newnode(2);
	root->left->left = newnode(4);
	root->left->right = newnode(5);
	root->right = newnode(3);
	root->right->right = newnode(7);
	root->right->left = newnode(6);
	root->right->left->right = newnode(8);
	
	// variable to store sum of leaf nodes
	int sum = 0;
	leafSum(root, &sum);
	cout << sum << endl;
	return 0;
}