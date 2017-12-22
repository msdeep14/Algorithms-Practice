// http://www.geeksforgeeks.org/longest-palindrome-substring-set-1/

#include <bits/stdc++.h>
using namespace std;

string longestPalidrome(string s){
	int n = s.length();
	int table[1000][1000];
	for(int i=0;i<=n;i++){
		for(int j=0;j<=n;j++)
			table[i][j] = 0;
	}
	for(int i=0;i<=n;i++){
		table[i][i] = 1;
	}

	int maxlen = 1;
	int beg = 0;

	for(int i=0;i<n-1;i++){
		if(s[i] == s[i+1]){
			table[i][i+1] = 1;
			maxlen = 2;
			beg = i;
		}
	}

	for(int len=3;len <= n; len++){
		for(int i=0;i<n-len+1;i++){
			int j = len+i-1;
			if(s[i] == s[j] && table[i+1][j-1]){
				table[i][j] = 1;
				maxlen = len;
				beg = i;
			}
		}
	}
	cout << "max len is " << maxlen << endl;
	return s.substr(beg,maxlen);
}

int main(){
	string s;
	cin>>s;
	string res = longestPalidrome(s);
	cout << res << endl;
	return 0;
}