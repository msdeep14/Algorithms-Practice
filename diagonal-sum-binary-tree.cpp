//http://www.geeksforgeeks.org/diagonal-sum-binary-tree/
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

void diagonalPrint(node *root, int d, map<int,vector<int> > &m){
	if(!root) return;
	m[d].push_back(root->data);
	diagonalPrint(root->left,d+1,m);
	diagonalPrint(root->right,d,m);
}

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

	map<int,vector<int> > m;
	diagonalPrint(root,0,m);
	map<int,vector<int> > :: iterator it;
	int sum = 0;
	for(it = m.begin(); it!=m.end(); it++){
		sum = 0;
		for(int i=0;i<it->second.size();i++){
			sum+=it->second[i];
		}
		cout<<sum<<" ";
	}
	cout<<endl;
	return 0;
}