// http://www.geeksforgeeks.org/find-number-of-islands/
// allowed to move in four directions
#include <bits/stdc++.h>
using namespace std;

void dfs(int arr[][5], int visited[][5], int n, int m, int i, int j){
	arr[i][j] = 0;
	if(i>=1 && j>=0 && i<n && j<m && arr[i-1][j]) dfs(arr,visited,n,m,i-1,j);
	if(i>=0 && j>=0 && i<n-1 && j<m && arr[i+1][j]) dfs(arr,visited,n,m,i+1,j);
	if(i>=0 && j>=1 && i<n && j<m && arr[i][j-1]) dfs(arr,visited,n,m,i,j-1);
	if(i>=0 && j>=0 && i<n && j<m-1 && arr[i][j+1]) dfs(arr,visited,n,m,i,j+1);
}

int main(){
	int arr[][5] = {{1,1,0,0,0},{0,1,0,0,1},{1,0,0,1,1},{0,0,0,0,0},{1,0,1,0,1}};
	int visited[5][5];
	int n=5, m =5;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			visited[i][j] = 0;
		}
	}
	int count = 0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(arr[i][j]){
				dfs(arr,visited,n,m,i,j);
				count+=1;
			}
		}
	}
	cout << count << endl;

	return 0;
}
