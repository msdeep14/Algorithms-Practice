//http://practice.geeksforgeeks.org/problems/array-to-bst/0
//
#include<bits/stdc++.h>
using namespace std;
struct node {
    int data;
    node *left;
    node *right;
};
node *getnode(int data){
    node * newnode = new node();
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
}
node *construct(int arr[],int start,int end){
    if(start > end) return  NULL;
    int mid = (start + end)/2;
    node *root = getnode(arr[mid]);
    root->left = construct(arr,start,mid-1);
    root->right = construct(arr,mid+1,end);
    return root;
}
void preorder(node *root){
    if(!root) return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
int main(){
    int t,n;
    int arr[10005];
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        node * root = construct(arr,0,n-1);
        preorder(root);
        cout<<endl;
    }
    return 0;
}
