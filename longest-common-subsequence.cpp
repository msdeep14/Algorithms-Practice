// longest common subsequence

#include <bits/stdc++.h>
using namespace std;

int longestCommonSubsequence(string a, string b, int n, int m){
	int dp[n+1][m+1];
	for(int i = 0;i<= n;i++){
		for(int j=0;j<=m;j++){
			if(i == 0 || j == 0) dp[i][j] = 0;
			else if(a[i-1] == b[j-1]){
				dp[i][j] = dp[i-1][j-1] + 1;
			}else{
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			}
		}
	}
	string res;
	int i = n, j = m;
	while(true){
		
		if(a[i] == b[j]){
			res.push_back(a[i]);
			if(i==0 && j==0) break;
			i--;
			j--;	
		}else{
			if(dp[i-1][j] > dp[i][j-1]) i--;
			else j--;
		}


	}
	reverse(res.begin(),res.end());
	cout << res << endl;

	return dp[n][m];
}

int main(){
	string a = "abcdaf";
	string b = "acbcf";
	int n = a.length();
	int m = b.length();
	int res = longestCommonSubsequence(a,b,n,m);
	cout << res << endl;
	return 0;
}