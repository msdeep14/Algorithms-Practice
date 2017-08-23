// http://www.geeksforgeeks.org/find-sum-left-leaves-given-binary-tree/

// CPP program to find total sum
// of right leaf nodes
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

// utility function to calculate sum 
// of right leaf nodes
void rightLeafSum(node *root, int *sum){
	if(!root) 
		return;

	// check if the right child of root 
	// is leaf node
	if(root->right)
		if(!root->right->left  &&  !root->right->right)
			*sum += root->right->data;

	rightLeafSum(root->left, sum);
	rightLeafSum(root->right, sum);
}

// driver program
int main(){
	//contruct binary tree
	node *root = getnode(1);
	root->left = getnode(2);
	root->left->left = getnode(4);
	root->left->right = getnode(5);
	root->left->left->right = getnode(2);
	root->right = getnode(3);
	root->right->right = getnode(8);
	root->right->right->left = getnode(6);
	root->right->right->right = getnode(7);

	// variable to store sum of right leaves
	int sum = 0;
	rightLeafSum(root, &sum);
	cout << sum << endl;
	return 0;
}