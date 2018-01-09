// https://www.geeksforgeeks.org/construct-a-binary-tree-from-postorder-and-inorder/
#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *left , *right;
};

Node *getNode(int data){
    Node *temp = new Node();
    temp->data = data;
    temp->left = temp->right = NULL;
}

int search(int in[], int data, int l, int r){
    for(int i=l ;i<=r; i++){
        if(in[i] == data){
            return i;
        }
    }
    return -1;
}

Node *buildTree(int in[], int post[], int inStart, int inEnd,int n){
    static int postIndex = n-1;
    if(inStart > inEnd)
        return NULL;
    Node *root = getNode(post[postIndex]);
    postIndex -= 1;
    if(inStart == inEnd)
        return root;

    int inIndex = search(in,root->data,inStart, inEnd);
    if(inIndex == -1){
        cout << "Error\n";
        return NULL;
    }
    
    root->right = buildTree(in, post, inIndex+1, inEnd,n);
    root->left = buildTree(in,post,inStart,inIndex-1,n);
    return root;

}

void inorder(Node *root){
    if(!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main(){
    int post[] = {8,4,5,2,6,7,3,1};
    int in[] = {4,8,2,5,1,6,3,7};
    Node *root = buildTree(in,post,0,7,8);
    inorder(root);
    return 0;
}