// https://www.geeksforgeeks.org/construct-tree-from-given-inorder-and-preorder-traversal/
#include <bits/stdc++.h>
using namespace std;

struct Node{
    char data;
    Node *left , *right;
};

Node *getNode(char data){
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

Node *buildTree(int in[], int pre[], int inStart, int inEnd){
    static int preIndex = 0;
    if(inStart > inEnd)
        return NULL;
    Node *root = getNode(pre[preIndex]);
    preIndex += 1;
    if(inStart == inEnd)
        return root;

    int inIndex = search(in,root->data,inStart, inEnd);
    if(inIndex == -1){
        cout << "Error\n";
        return NULL;
    }
    root->left = buildTree(in,pre,inStart,inIndex-1);
    root->right = buildTree(in, pre, inIndex+1, inEnd);
    return root;

}

void inorder(Node *root){
    if(!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main(){
    int pre[] = {'A','B','D','E','C','F'};
    int in[] = {'D','B','E','A','F','C'};
    Node *root = buildTree(in,pre,0,5);
    inorder(root);
    return 0;
}