// http://www.geeksforgeeks.org/bottom-view-binary-tree/
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

// int height(node *root){
// 	if(!root) return 0;
// 	int l = height(root->left);
// 	int r = height(root->right);
// 	if(l>r) return l+1;
// 	else return r+1;
// }

void bottomView(node *root, int hd, map<int,pair<int,int> > &m,int h){
	if(!root) return;
	//int h = height(root);
	if(m.find(hd) == m.end())
	m[hd] = make_pair(root->data,h);
	else{
		if(h>m[hd].second){
			m[hd].first = root->data;
			m[hd].second = h;
		}
	}
	h++;
	bottomView(root->left,hd-1,m,h);
	bottomView(root->right,hd+1,m,h);
}

int main(){
	//contruct binary tree
	node *root = getnode(20);
	root->left = getnode(8);
	root->left->left = getnode(5);
	root->left->right = getnode(3);
	root->left->right->left = getnode(10);
	root->left->right->right = getnode(14);
	root->right = getnode(22);
	root->right->right = getnode(25);
	
	map<int,pair<int,int> > m;
	bottomView(root,0,m,0);
	map<int,pair<int,int> > :: iterator it;
	//int sum = 0;
	for(it = m.begin(); it!=m.end(); it++){
		cout<<it->second.first<<" ";//<<it->second.second<<endl;
	}
	cout<<endl;
	return 0;
}