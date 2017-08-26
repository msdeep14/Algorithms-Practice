// http://www.geeksforgeeks.org/check-for-identical-bsts-without-building-the-trees/
#include <bits/stdc++.h>
using namespace std;

int checkBst(int a[], int b[], int va[], int vb[], int index, int n){
	if(n == 0) return 1;
	
}

int main(){
	int a[] = {2,4,1,3};
	int b[] = {2,4,1,3};
	int va[] = {0};
	int vb[] = {0};
	int res = checkBst(a,b,va,vb,0,4);
	return 0;
}