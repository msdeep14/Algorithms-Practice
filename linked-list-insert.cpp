#include<iostream>
using namespace std;

/*
Structure of the linked list node is as*/
struct node
{
    int data;
    struct node *next;
};


// function inserts the data in front of the list
void insertAtBegining(struct node** headRef, int newData)
{
    // Code here
    if(*headRef == NULL){
        (*headRef)->data = newData;
        (*headRef)->next = NULL;
    }else{
        node *newnode = new node();
        newnode->data = newData;
        newnode->next = (*headRef);
        (*headRef) = newnode;
    }
}

// function appends the data at the end of the list
void insertAtEnd(struct node** headRef, int newData)
{
    // Code here
    node *newnode = new node();
    newnode->data = newData;
    newnode->next = NULL;
    if(*headRef ==NULL){
        *headRef = newnode;
        return;
    }

    node* curr = *headRef;
    while(curr->next!=NULL){
        curr = curr->next;
    }
    curr->next = newnode;
    return;
}

node* deleteNode(node *head,int x)
{
    //Your code here
    if(head!=NULL){
        if(x==0){
            node *temp = head;
            head = head->next;
            delete temp;
            return head;
        }else{
            node *temp = head;
            for(int i=0;i<x-1;i++){
                head = head->next;
            }
            node *todelete = head->next;
            head->next = todelete->next;
            delete todelete;
            return temp;
        }
    }
}

bool search(node *head,int x){
    if(head==NULL) return false;
    if(head->data == x) return true;
    search(head->next,x);
}

int main(){
    int t,n,k,num;
    cin>>t;
    while(t--){
        cin>>n;
        node *head = NULL;
        for(int i=0;i<n;i++){
            // cin>>num>>k;
            // if(k==0) insertAtBegining(&head,num);
            // else insertAtEnd(&head,num);
            cin>>num;
            insertAtEnd(&head,num);
        }
        //delete node
        /*
        cout<<"enter pos to delete:: \n";
        int pos;
        cin>>pos;
        deleteNode(head,pos);
        */

        //search for nodevalue
        int val;
        cout<<"enter value to be searched:: \n";
        cin>>val;
        bool res = search(head,val);
        if(res == true)cout<<"value found\n";
        else cout<<"value not found\n";

        while(head!=NULL){
            cout<<head->data<<" ";
            head = head->next;
        }
        cout<<endl;
        delete head;
    }
    return 0;
}
