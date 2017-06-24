//http://www.geeksforgeeks.org/find-duplicates-in-on-time-and-constant-extra-space/
//find-duplicates-in-on-time-and-constant-extra-space
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,t;
    cin>>n;
    int arr[100005];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<n;i++){
        if(arr[abs(arr[i])]>0 && arr[i] != INT_MAX){
            arr[abs(arr[i])] = -arr[abs(arr[i])];
        }else if(arr[abs(arr[i])] <0){
            cout<<abs(arr[i])<<" ";
            arr[abs(arr[i])] = INT_MAX;
        }
    }
    return 0;
}
