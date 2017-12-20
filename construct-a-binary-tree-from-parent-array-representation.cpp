// http://www.geeksforgeeks.org/construct-a-binary-tree-from-parent-array-representation/
#include <bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	Node *left, *right;
};

Node *newNode(int data){
	Node *temp = new Node();
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}

void createNode(int parent[], int i, Node* created[],Node **root){
	if(created[i]) return;
	created[i] = newNode(i);
	if(parent[i] == -1){
		*root = created[i];
		return;
	}
	if(!created[parent[i]]){
		createNode(parent,parent[i],created,root);
	}
	Node *p = created[parent[i]];
	if(!p->left)
		p->left = created[i];
	else p->left = created[i];
}

Node *create(int arr[], int n){
	Node* created[1000];
	for(int i=0;i<n;i++) created[i] = NULL;
	Node *root = NULL;
	for(int i=0;i<n;i++)
		createNode(arr,i,created,&root);
	return root;
}

void inorder(Node *root){
	if(!root) return;
	inorder(root->left);
	cout << root->data << " ";
	inorder(root->right);
}

int main(){
	int n = 7;
	int arr[] = {1,5,5,2,2,-1,3};
	Node *root = create(arr,n);
	inorder(root);
	return 0;
}