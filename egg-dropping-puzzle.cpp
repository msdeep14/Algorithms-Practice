// http://practice.geeksforgeeks.org/problems/egg-dropping-puzzle/0
#include <bits/stdc++.h>
using namespace std;

// n = eggs
// k = floors
int findMinSteps(int n, int k){
	int dp[n+1][k+1] = {0};
	for(int i =0 ; i<=k;i++){
		dp[1][i] = i;
	}
	int c = 0;
	for(int e = 2;e<=n;e++){
		for(int f = 1;f<=k;f++){
			dp[e][f] = INT_MAX;
			for(int l = 1;l<=f;l++){
				c = 1 + max(dp[e-1][l-1], dp[e][f-l]);
				if(c < dp[e][f]){
					dp[e][f] = c;
				}
			}
		}
	}

	return dp[n][k];
}

int main(){
	int t,n,k;
	cin>>t;
	while(t--){
		cin>>n>>k;
		int ans = findMinSteps(n,k);
		cout << ans << endl;
	}
	return 0;
}