//
//nth-catalan-number
#include <iostream>
using namespace std;
int main(){
	int t,n;
	cin>>t;
	long long int arr[105];
	for(int i=0;i<105;i++) arr[i]=0;
	arr[0]=1;
	arr[1]=1;
	for(long long int i=2;i<101;i++){
		for(long long int j = 0;j<i;j++){
			arr[i] += arr[j]*arr[i-j-1];
		}
	}
	while(t--){
		cin>>n;
		cout<<arr[n]<<endl;
	}
	return 0;
}