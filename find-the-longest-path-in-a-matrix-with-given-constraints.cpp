// https://www.geeksforgeeks.org/find-the-longest-path-in-a-matrix-with-given-constraints/
#include <bits/stdc++.h>
using namespace std;

int findLongestPath(int dp[][4], int arr[][3], int i, int j, int n, int m){
	if(i>=n || i<0 || j>=n || j<0)
		return 0;
	if(dp[i][j] != -1)
		return dp[i][j];
	if(i<n-1 && arr[i+1][j] == arr[i][j]+1)
		return dp[i][j] = 1 + findLongestPath(dp,arr,i+1,j,n,m);
	if(i>0 && arr[i][j]+1 == arr[i-1][j])
		return dp[i][j] = 1 + findLongestPath(dp,arr,i-1,j,n,m);
	if(j<n-1 && arr[i][j]+1 == arr[i][j+1])
		return dp[i][j] = 1 + findLongestPath(dp,arr,i,j+1,n,m);
	if(j>0 && arr[i][j]+1 == arr[i][j-1])
		return dp[i][j] = 1 + findLongestPath(dp,arr,i,j-1,n,m);

	return dp[i][j] = 1;
}

int main(){
	int n = 3, m = 3;
	int arr[3][3] = {{1,2,9},{5,3,8},{4,6,7}};
	int dp[4][4];
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++)
			dp[i][j] = -1;
	}
	int res = 1;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(dp[i][j] == -1){
				int nres = findLongestPath(dp,arr,i,j,n,m);
				res = max(res,dp[i][j]);
			}
		}
	}
	cout << res << endl;
	return 0;
}	