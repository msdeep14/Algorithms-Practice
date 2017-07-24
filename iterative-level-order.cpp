// CPP program to print
// level of given node in binary tree
// iterative approach
/*
binary tree
root is at level 1

                20
              /   \
            10    30
           / \    / \
          5  15  25  40
             /
            12
*/
#include <iostream>
#include <queue>
using namespace std;

// node of binary tree
struct node{
	int data;
	node *left;
	node *right;
};

// utility function to create
// a new node
node * getnode(int data){
	node * newnode = new node();
	newnode->data = data;
	newnode->left = NULL;
	newnode->right = NULL;
}

// utility function to return level of given node
int getlevel(node *root, int data){
	queue<node*> q;
	int level = 1;
	q.push(root);
	// extra NULL is pushed to keep track
	// of all the nodes to be pushed before
	// level is incremented by 1
	q.push(NULL);
	while(!q.empty()){
		node *temp = q.front();
		q.pop();
		if(temp == NULL){
			if(q.front() != NULL){
				q.push(NULL);
			}
			level +=1;
		}
		else{
			if(temp->data == data){
				return level;
			}
			if(temp->left){
				q.push(temp->left);
			}
			if(temp->right){
				q.push(temp->right);
			}
		}
	}
	return 0;
}
int main(){
	// create a binary tree
	node *root = getnode(20);
	root->left = getnode(10);
	root->right = getnode(30);
	root->left->left = getnode(5);
	root->left->right = getnode(15);
	root->left->right->left = getnode(12);
	root->right->left = getnode(25);
	root->right->right = getnode(40);

	// return level of node
	int level = getlevel(root, 30);
	(level != 0)?(cout << "level of node 30 is " << level << endl):(cout << "node 30 not found" << endl);
	level = getlevel(root, 12);
	(level != 0)?(cout << "level of node 12 is " << level << endl):(cout << "node 12 not found" << endl);
	level = getlevel(root, 25);
	(level != 0)?(cout << "level of node 25 is " << level << endl):(cout << "node 25 not found" << endl);
	level = getlevel(root,27);
	(level != 0)?(cout << "level of node 27 is " << level << endl):(cout << "node 27 not found" << endl);
	return 0;
}