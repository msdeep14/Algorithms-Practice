//http://practice.geeksforgeeks.org/problems/subarray-with-given-sum/0
//
//
#include<bits/stdc++.h>
using namespace std;
int main(){
    int t,n,x;
    int arr[10005];
    cin>>t;
    while(t--){
        cin>>n>>x;
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        int start = 0;
        int sum = arr[0];
        int flag=0;
        for(int i=1;i<=n && flag == 0;i++){

            while(sum > x && start < i-1){
                sum = sum - arr[start];
                start++;
            }
            if(sum == x){
                cout<<start+1<<" "<<i<<endl;
                flag=1;
            }
            if(i < n)
                sum += arr[i];
        }
        if(flag == 0)cout<<"-1\n";

    }
    return 0;
}
