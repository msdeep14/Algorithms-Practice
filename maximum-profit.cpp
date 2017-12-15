// http://practice.geeksforgeeks.org/problems/maximum-profit/0
#include <bits/stdc++.h>
using namespace std;

int maxProfit(int arr[], int n, int k){
	int dp[k+1][n+1];
	for(int i = 0;i <= k ;i++){
		for(int j=0;j<n;j++){
			if(i == 0 || k == 0) dp[i][j] = 0;
			else{
				int mx = INT_MIN;
				for(int m=0;m<j;m++){
					mx = max(mx,arr[j] - arr[m] + dp[i-1][m]);
				}
				dp[i][j] = max(mx,dp[i][j-1]);
			}
		}
	}
	return dp[k][n-1];
}

int main(){
	int t, n,k;
	cin>>t;
	int arr[1000];
	while(t--){
		cin>>k>>n;
		for(int i=0;i<n;i++)cin>>arr[i];
		cout << maxProfit(arr, n, k) << endl;
	}
	return 0;
}