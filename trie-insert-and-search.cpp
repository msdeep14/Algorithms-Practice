//http://practice.geeksforgeeks.org/problems/trie-insert-and-search/0
//trie-insert-and-search
#include<iostream>
#include<vector>
#include<string>
using namespace std;
struct node{
    struct node *child[26];
    bool isleaf;
};

node *getnode(){
    node *pnode = new node();
    for(int i=0;i<26;i++){
        pnode->child[i] =  NULL;
    }
    pnode->isleaf = false;
    return pnode;
}

void insert(node *root,string s){
    int len = s.length();
    node *crawl = root;
    for(int i=0;i<len;i++){
        int index = s[i]-97;
        if(!crawl->child[index]){
            crawl->child[index]=getnode();
        }
        crawl=crawl->child[index];
    }
    crawl->isleaf = true;
}

int search(node* root,string s){
    int len = s.length();
    node *crawl = root;
    for(int i=0;i<len;i++){
        int index = s[i]-97;
        if(!crawl->child[index]) return 0;
        crawl = crawl->child[index];
    }
    if(crawl!=NULL && crawl->isleaf==true)return 1;
}

int main(){
    int t,n;
    cin>>t;
    while(t--){
        vector <string> vec;
        string s;
        string str;
        cin>>n;
        node *root = getnode();
        for(int i=0;i<n;i++){
            cin>>s;
            vec.push_back(s);
            insert(root,s);
        }
        cin>>str;
        int res = search(root,str);
        (res==1)?(cout<<"1\n"):(cout<<"0\n");
    }
    return 0;
}
