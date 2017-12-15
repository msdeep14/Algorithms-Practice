//http://practice.geeksforgeeks.org/problems/greater-on-right-side/0
//
#include<bits/stdc++.h>
using namespace std;
int main(){
    int t,n;
    int arr[10005];
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        int max = arr[n-1];
        for(int i=n-2;i>=0;i--){
            if(arr[i]>max){
                max = arr[i];
            }
        }
        //traverse the array
        //get max for all
        //print the array
    }
    return 0;
}
