// https://www.geeksforgeeks.org/shortest-common-supersequence/
#include <bits/stdc++.h>
using namespace std;

int super(string s1, string s2, int n, int m){
	int dp[n+1][m+1];
	for(int i=0;i<=n;i++){
		for(int j=0;j<=m;j++){
			if(i == 0)
				dp[i][j] = j;
			else if(j == 0)
				dp[i][j] = i;
			else if(s1[i-1] == s2[j-1])
				dp[i][j] = 1 + dp[i-1][j-1];
			else 
				dp[i][j] = 1 + min(dp[i-1][j], dp[i][j-1]);
		}
	}
	return dp[n][m];
}

int lcsApproach(string s1, string s2, int n, int m){
	int dp[n+1][m+1];
	for(int i=0;i<=n;i++){
		for(int j=0;j<=m;j++){
			if(i == 0 || j == 0)
				dp[i][j] = 0;
			else if(s1[i-1] == s2[j-1])
				dp[i][j] = 1 + dp[i-1][j-1];
			else
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
		}
	}
	return m+n-dp[n][m];
}

int main(){
	string s1 = "aggtab";
	string s2 = "gxtxayb";
	int n = s1.length();
	int m = s2.length();
	int res = super(s1,s2,n,m);
	cout << res << endl;
	int res2 = lcsApproach(s1,s2,n,m);
	cout << res2 << endl;
	return 0;
}