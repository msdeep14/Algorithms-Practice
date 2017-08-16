/**/

// CPP program to return max
// in struct array
#include <iostream>
#include <climits>
using namespace std;

// struct TreeNode
// 1 feet = 12 inches
struct TreeNode{
	int feet;
	int inches;
};

// return max of the array
int findMax(TreeNode arr[], int n){
	int mx = INT_MIN;
	for(int i = 0; i < n; i++){
		int temp = 12*(arr[i].feet) + arr[i].inches;
		mx = max(mx,temp);
	}
	return mx;
}

// driver program
int main(){

	// initialise the array
	TreeNode arr[] = {
		{1,3},
		{10,5},
		{6,8},
		{3,7},
		{5,9}
	};
	int res = findMax(arr,5);
	cout << "max :: " << res << endl;
	return 0;
}