// https://www.geeksforgeeks.org/find-sub-array-sum-closest-0/
#include <bits/stdc++.h>
using  namespace std;

pair<int, int> sumClosest(int arr[], int n){
	vector<pair<int, int> > v;
	v.push_back(make_pair(0,-1));
	for(int i=1;i<=n;i++){
		v.push_back(make_pair((v[i-1].first+arr[i-1]), i-1));
	}
	
}

int main(){
	int arr[] = {-1,3,2,-5,4};
	int n = sizeof(arr)/sizeof(arr[0]);
	pair<int , int> p = sumClosest(arr,n);
	cout << p.first << " " << p.second << endl;
	return 0;
}