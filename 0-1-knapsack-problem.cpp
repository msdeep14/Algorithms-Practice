// http://practice.geeksforgeeks.org/problems/0-1-knapsack-problem/0

#include <bits/stdc++.h>
using namespace std;
void knapsack(int wt[], int val[], int n, int w){
	int dp[n+1][w+1];

	for(int i=0;i<=n;i++){
		for(int j=0;j<=w;j++){
			if(i==0 || j==0)
				dp[i][j]=0;
			else if(j<wt[i]){
				dp[i][j] = dp[i-1][j];
			}else{
				dp[i][j] = max(dp[i-1][j], val[i-1]+dp[i-1][j-wt[i-1]]);
			}
		}
	}
	cout<< dp[n][w] << endl;
}
int main(){
	int t,n,w;
	cin>>t;
	while(t--){
		cin>>n;
		cin>>w;
		int val[1000];
		int wt[1000];
		for(int i=0;i< n;i++) cin>>val[i];
		for(int i=0;i<n;i++) cin>>wt[i];

		knapsack(wt,val,n,w);
	}
	return 0;
}