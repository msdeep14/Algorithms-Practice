//
//k-anagrams-1

//method 2 -> using trie
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
struct node{
	struct node *child[26];
	bool isleaf;
	vector<int> list;
};

node* getnode(){
	node* pnode = new node();
	for(int i=0;i<26;i++){
		pnode->child[i] = NULL;
	}
	pnode->isleaf = false;
}

void insert(node *root, string s, int sindex){
	int len = s.length();
	node *pnode = root;
	for(int i=0;i<len;i++){
		int index = s[i]-97;
		if(!pnode->child[index]){
			pnode->child[index] = getnode();
		}
		pnode = pnode->child[index];
	}
	pnode->isleaf = true;
	pnode->list.push_back(sindex);
}

void traverse(node *root,vector<string> &vec,vector<int> &countvec){
	if(root == NULL) return;
	if(root->isleaf){
		/*for(int j =0;j<root->list.size();j++){
			cout<<vec[j]<<" ";
		}*/
		//cout<<root->list.size()<<" ";
		countvec.push_back(root->list.size());
	}
	for(int i=0;i<26;i++){
		traverse(root->child[i],vec,countvec);
	}
}

int main(){
	int t,n;
	cin>>t;
	while(t--){
		node * root = getnode();
		vector<string> vec;
		string s;
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>s;
			vec.push_back(s);
			sort(s.begin(),s.end());
			insert(root,s,i);
		}
		vector<int> countvec;
		traverse(root,vec,countvec);
		sort(countvec.begin(),countvec.end());
		for(int i=0;i<countvec.size();i++){
			cout<<countvec[i]<<" ";
		}
		cout<<endl;
	}
}

/*
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
using namespace std;
int main(){
	int t,n;
	cin>>t;
	while(t--){
		vector <string> vec;
		vector<int> countarr;
		cin>>n;
		string s;
		for(int i=0;i<n;i++){
			cin>>s;
			vec.push_back(s);
		}

		map<string,int> m;
		for(int i=0;i<vec.size();i++){
			sort(vec[i].begin(),vec[i].end());
			if(m.find(vec[i]) == m.end()){
				m[vec[i]] = 1;
			}else{
				int x = m[vec[i]];
				m[vec[i]] = x+1;
			}
		}
		map<string,int> :: iterator it;
		for(it = m.begin();it!=m.end();it++){
			countarr.push_back(it->second);
		}
		sort(countarr.begin(),countarr.end());
		 for(int i=0;i<countarr.size();i++){
		 	cout<<countarr[i]<<" ";
		 }
		 countarr.clear();
		 m.clear();
		 vec.clear();
		 cout<<endl;
	}
	return 0;
}*/
