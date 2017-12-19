// ugly numbers
#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	int arr[100005], res[100005];;
	cin>>n;
	int i2=0,i3=0,i5=0;
	int two=2,three=3,five=5;
	int next = 1;
	arr[0]=1;
	for(int i=1;i<n;i++){
		next = min(two,min(three,five));
		arr[i] = next;
		if(next == two){
			i2++;
			two = arr[i2]*2;
		}
		if(next == three){
			i3++;
			three = arr[i3]*3;
		}
		if(next == five){
			i5++;
			five = arr[i5]*5;
		}
	}
	cout << next << endl;
	// int sz = 100005;
	// for(int i=0;i<sz;i++){
	// 	arr[i] = 0;
	// }
	// arr[0] = 0;
	// arr[1] = 1;
	// arr[2] = 1;
	// arr[3] = 1;
	// arr[4] = 1;
	// arr[5] = 1;
	// res[1] = 1;
	// res[2] = 2;
	// res[3] = 3;
	// res[4] = 4;
	// res[5] = 5;
	// int j = 6;
	// for(int i=6; i<sz; i++){
	// 	if(i%5 == 0){
	// 		if(arr[i/5] == 1){
	// 			arr[i] = 1;
	// 			res[j++] = i;
	// 		}
	// 	}else if(i%3 == 0){
	// 		if(arr[i/3] == 1){
	// 			arr[i] = 1;
	// 			res[j++] = i;
	// 		}
	// 	}else if(i%2 == 0){
	// 		if(arr[i/2] == 1){
	// 			arr[i] = 1;
	// 			res[j++] = i;
	// 		}
	// 	}
	// }
	// cout << res[n] << endl;

	return 0;
}