// https://www.geeksforgeeks.org/find-three-closest-elements-from-given-three-sorted-arrays/
#include <bits/stdc++.h>
using namespace std;

int main(){
	int arr[] = {1,4,10};
	int brr[] = {2,15,20};
	int crr[] = {10,12};
	int p = 3, q = 3, r = 2;
	int i=0,ri=0,j=0,rj=0,k=0,rk=0;
	int diff = INT_MAX;
	while(i<p && j<q && k<r){
		int maxx = max(arr[i], max(brr[j],crr[k]));
		int minn = min(arr[i], min(brr[j],crr[k]));
		if(maxx - minn < diff){
			diff = maxx - minn;
			ri = i;
			rj = j;
			rk = k;
		}
		if(diff == 0) break;
		if(arr[i] == minn) i+=1;
		else if(brr[j] == minn) j+=1;
		else k+=1;
	}
	cout << arr[ri] << " " << brr[rj] << " " << crr[rk] << endl;
	return 0;
}