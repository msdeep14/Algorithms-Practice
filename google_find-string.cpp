/*
Given a string and array of strings, find whether the array contains a string with one character difference
from the given string. Array may contain string of different lengths.

Ex: Given string

banana
and array is

[bana, apple, banaba, bonanza, banamf]
and the outpost should be true as banana and banaba are one character difference.
*/
#include <bits/stdc++.h>
using namespace std;
struct Trienode{
    bool isleaf;
    Trienode *child[26];
};
Trienode *getnewnode(){
    Trienode *newnode = new Trienode();
    newnode->isleaf = false;
    for(int i=0;i<26;i++){
        newnode->child[i] = NULL;
    }
    return newnode;
}
void build(Trienode *root, string s){
    int len = s.length();
    Trienode *crawl = root;
    for(int i=0;i<len;i++){
        int index = s[i] - 97;
        if(!crawl->child[index]){
            crawl->child[index] = getnewnode();
        }
        crawl = crawl->child[index];
    }
    crawl->isleaf = true;
}
int search(Trienode *root, string s){
    Trienode *crawl = root;
    Trienode *prev = NULL;
    int len = s.length();
    int flag = 0;
    int i = 0, j = 0;
    int start = 0;
    for(i=0;i<len;i++){
        int index = s[i] - 97;
        if(!crawl->child[index] && flag == 0){
            flag = 1;
        }else if(!crawl->child[index] && flag == 1){
            return 0;
        }
        if(flag == 1){
            start = i;
            int flag2 = 0;
            //check if there exists a word of len = start + 1;
            if(start + 1 == len){
                Trienode *temp = crawl;
                for(int k=0;k<26;k++){
                    if(temp->child[k]){
                        temp = temp->child[k];
                        if(temp->isleaf == 1){
                            flag2 = 1;
                            return 1;
                        }
                    }
                }
                if(flag2 == 0) return 0;
            }
            break;
        }
        crawl = crawl->child[index];
    }
    int check = 0;
    if(flag == 1){
        for(j=0;j<26;j++){
            if(crawl->child[j]){
                prev = crawl;
                check = 1;
                crawl = crawl->child[j];
                for(i = start+1;i<len;i++){
                    int index = s[i] - 97;
                    if(!crawl->child[index]){
                        break;
                    }
                    crawl = crawl->child[index];
                }
            }
            if(i == len && crawl->isleaf == 1){
                return 1;
            }else if(check == 1){
                crawl = prev;
            }
        }
        if(j == 26) return 0;
    }
    return 0;
}
int main(){
    vector<string> arr;
    arr.push_back("bana");
    arr.push_back("apple");
    arr.push_back("banaba");
    arr.push_back("bonanza");
    arr.push_back("banamf");
    Trienode *root = getnewnode();
    for(int i=0;i<arr.size();i++){
        build(root,arr[i]);
    }
    vector<string> testarr;
    testarr.push_back("banana");
    testarr.push_back("bannna");
    testarr.push_back("appl");
    testarr.push_back("abcd");
    for(int i=0;i<testarr.size();i++){
        int res = search(root,testarr[i]);
        (res == 1)?(cout<<"Yes\n"):(cout<<"No\n");
    }
    return 0;
}

/*

struct Node {

    bool exist;
    Node *children[256];
};

Node *root;

bool dfs(Node *n, const string &s, int pos, int cnt) {
    if (cnt > 1)
        return false;
    if (pos == s.size())
        return cnt == 1;

    for (int i = 0; i < 256; ++i) {
        Node *c = n->children[i];
        if (c != nullptr) {
            if (s[pos] == i && dfs(c, s, pos + 1, cnt) ||
                    s[pos] != i && dfs(c, s, pos + 1, cnt + 1))
                return true;
        }
    }
}

bool hasSimilar(const string &s) {
    return dfs(root, s, 0, 0);
}

*/