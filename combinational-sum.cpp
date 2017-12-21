// http://www.geeksforgeeks.org/combinational-sum/
#include <bits/stdc++.h>
using namespace std;

void findSum(vector<int> &arr, vector<vector<int> > &res, vector<int> &r, int n, int sum, int i){
	if(sum < 0) 
		return;
	if(sum == 0){
		res.push_back(r);
		return;
	}
	while(i < n && sum-arr[i]>=0){
		r.push_back(arr[i]);
		findSum(arr,res,r,n,sum-arr[i],i);
		i++;
		r.pop_back();
	}
}

int main(){
	int n,x,y;
	vector<int> arr;
	cin>>n>>x;
	for(int i=0;i<n;i++){
		cin>>y;
		arr.push_back(y);
	}
	sort(arr.begin(), arr.end());
	arr.erase(unique(arr.begin(),arr.end()),arr.end());
	vector<vector<int> > res;
	vector<int> r;
	findSum(arr,res,r,n,x,0);
	for(int i=0;i<res.size();i++){
		for(int j=0;j<res[i].size();j++)
			cout << res[i][j] << " ";
		cout << endl;
	}

	return 0;
}