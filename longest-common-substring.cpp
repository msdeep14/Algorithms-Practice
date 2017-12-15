// http://practice.geeksforgeeks.org/problems/longest-common-substring/0
#include <bits/stdc++.h>
using namespace std;
int match(string a, string b, int m, int n){
	int store[m+1][n+1];
	int mx = 0;
	for(int i=0;i<=m;i++){
		for(int j=0;j<=n;j++){
			if(i==0 || j == 0){
				store[i][j] = 0;
			}
			else if(a[i-1] == b[j-1]){
				store[i][j] = store[i-1][j-1] + 1;
				mx = max(mx,store[i][j]);
			}else{
				store[i][j] = 0;
			}
		}
	}
	return mx;
}
int main(){
	string s1,s2;
	cin>>s1>>s2;
	int m = s1.length();
	int n = s2.length();
	int res = match(s1,s2,m,n);
	cout<<"longest substring :: "<<res<<endl;
	return 0;
}