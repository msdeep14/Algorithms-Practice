//http://practice.geeksforgeeks.org/problems/maximum-difference/0
//maximum-difference
#include<bits/stdc++.h>
using namespace std;
int main(){
    int t,n;
    int arr[105];
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        int mn = arr[0];
        int mx = arr[1] - arr[0];
        for(int i=1;i<n;i++){
            if(arr[i]-mn > mx){
                mx = arr[i] - mn;
            }
            if(arr[i]<mn){
                mn = arr[i];
            }
        }
        cout<<mx<<endl;
    }
    return 0;
}
