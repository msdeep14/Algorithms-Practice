//http://www.geeksforgeeks.org/check-for-children-sum-property-in-a-binary-tree/
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
int check(node *root){
    if(root == NULL || (root->left == NULL && root->right == NULL)) return 1;
    int x=0,y=0;
    if(root->left != NULL) x = root->left->data;
    if(root->right != NULL) y = root->right->data;
    if(root->data == x+ y && check(root->left) && check(root->right)) return 1;
    else return 0;


    // if(root->left != NULL || root->right != NULL){
    //     if(root->left != NULL) x = root->left->data;
    //     if(root->right != NULL) y = root->right->data;
    //     if(root->data == x+y){
    //         check(root->left);
    //         check(root->right);
    //     }else if(root->left == NULL && root->right == NULL) return 1;
    //     else{
    //         return 0;
    //     }
    // }
}

int main(){
    node * root = getnewnode(10);
    root->left = getnewnode(8);
    root->right = getnewnode(2);
    root->left->left = getnewnode(5);
    root->left->right = getnewnode(2);
    int x = check(root);
    cout<<x<<endl;
    return 0;
}
