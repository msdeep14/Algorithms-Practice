// https://www.geeksforgeeks.org/dynamic-programming-set-5-edit-distance/

#include <bits/stdc++.h>
using namespace std;

int editDistanceRec(string s1, string s2, int n, int m){
	if(n == 0) return n;
	if(m == 0) return m;
	if(s1[n-1] == s2[m-1]) 
		return editDistanceRec(s1,s2,n-1,m-1);
	else 
		return 1+min(editDistanceRec(s1,s2,n-1,m-1),min(editDistanceRec(s1,s2,n,m-1), editDistanceRec(s1,s2,n-1,m)));
}

int editDistanceDP(string s1, string s2, int n, int m){
	int dp[n+1][m+1];
	for(int i=0;i<=n;i++){
		for(int j=0;j<=m;j++){
			if(i == 0) dp[i][j] = i;
			else if(j == 0) dp[i][j] = j;
			else if(s1[i] == s2[j])
				dp[i][j] = dp[i-1][j-1];
			else 
				dp[i][j] = 1 + min(dp[i-1][j-1] , min(dp[i-1][j], dp[i][j-1]));
		}
	}
	return dp[n][m];
}

int main(){
	string s1,s2;
	cin>>s1>>s2;
	int n = s1.length();
	int m = s2.length();
	int res = editDistanceRec(s1,s2,n,m);
	cout << res << endl;
	int res2 = editDistanceDP(s1,s2,n,m);
	cout << res2 << endl;
	return 0;
}