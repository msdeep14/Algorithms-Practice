// https://www.geeksforgeeks.org/dynamic-programming-set-13-cutting-a-rod/
#include <bits/stdc++.h>
using namespace std;

int cuttingRod(int arr[], int n){
	int maxx = INT_MIN;
	int dp[n+1][n+1];
	for(int i=0;i<n;i++){
		dp[i][0] = 0;
		dp[0][i] = 0;
	}
	// for(int j=1;j<=n;j++){
	// 	dp[0][j] = arr[i]*j; 
	// }
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(j>=i){
				dp[i][j] = max(dp[i-1][j], arr[i]+dp[i][i-j]);
			}else{
				dp[i][j] = dp[i-1][j];
			}
		}
	}
	return dp[n][n];
}

int main(){
	int arr[] = {1,5,8,9,10,17,17,20};
	int n = sizeof(arr)/sizeof(arr[0]);
	int res = cuttingRod(arr, n);
	cout << res << endl;
	return 0; 
}