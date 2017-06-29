//http://www.geeksforgeeks.org/inorder-tree-traversal-without-recursion/
#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node *left;
    node *right;
};
node * getnewnode(int data){
    node *newnode = new node();
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
}
void inorder(node *root){
    stack<node *> s;
    //if(root) s.push(root);
    int flag = 1;
    node *curr = root;
    while(flag){
        if(curr){
            s.push(curr);
            curr = curr->left;
        }else{
            if(!s.empty()){
                curr = s.top();
                s.pop();
                cout<<curr->data<<" ";
                curr = curr->right;
            }else{
                flag = 0;
            }
        }
    }
}
int main(){
    node * root = getnewnode(1);
    root->left = getnewnode(2);
    root->right = getnewnode(3);
    root->left->left = getnewnode(4);
    root->left->right = getnewnode(5);
    inorder(root);
    return 0;
}
