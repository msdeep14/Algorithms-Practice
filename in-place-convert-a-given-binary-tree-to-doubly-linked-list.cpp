// https://www.geeksforgeeks.org/in-place-convert-a-given-binary-tree-to-doubly-linked-list/
#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node *left;
    Node *right;
};
Node * getnewnode(int data){
    Node *newnode = new Node();
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
}

Node *convertToDLL(Node *root){
	if(!root) 
		return root;
	if(root->left){
		Node *l = convertToDLL(root->left);
		for(;l->right;l=l->right);
		root->left = l;
		l->right = root;
	}
	if(root->right){
		Node *r = convertToDLL(root->right);
		for(;r->left;r=r->left);
		r->left = root;
		root->right = r;
	}
	return root;
}


int main(){
    Node * root = getnewnode(10);
    root->left = getnewnode(12);
    root->right = getnewnode(15);
    root->left->left = getnewnode(25);
    root->left->right = getnewnode(30);
    root->right->left = getnewnode(36);

    Node *res = convertToDLL(root);
    while(res->left)
    	res = res->left;

    while(res){
    	cout << res->data << " ";
    	res = res->right;
    }
    return 0;
}
