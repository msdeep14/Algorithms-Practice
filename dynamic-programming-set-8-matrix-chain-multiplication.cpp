// https://www.geeksforgeeks.org/dynamic-programming-set-8-matrix-chain-multiplication/
#include <bits/stdc++.h>
using namespace std;

int matrixOrder(int p[], int i, int j){
	if(i == j) return 0;
	int k, minn = INT_MAX, count;

	for(int k=i;k<j;k++){
		count = matrixOrder(p,i,k) + matrixOrder(p,k+1,j) + p[i-1]*p[k]*p[j];
		if(count < minn)
			minn = count;
	}
	return minn;
}

int matrixOrderDP(int p[], int n){
	int m[n+1][n+1];
	for(int i=1;i<n;i++)
		m[i][i] = 0;

	for(int l=2;l<n;l++){
		for(int i=1;i<n-l+1;i++){
			int j=i+l-1;
			m[i][j] = INT_MAX;
			for(int k=i;k<j;k++){
				int q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
				if(q < m[i][j])
					m[i][j] = q;
			}	
		}
	}
	return m[1][n-1];
}

int main(){
	int p[] = {1,2,3,4};
	int n = sizeof(p)/sizeof(p[0]);
	// int res = matrixOrder(p, 1, n-1);
	int res = matrixOrderDP(p,n);
	cout << res << endl;
	return 0;
}