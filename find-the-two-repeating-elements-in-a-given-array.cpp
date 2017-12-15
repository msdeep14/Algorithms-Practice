//http://www.geeksforgeeks.org/find-the-two-repeating-elements-in-a-given-array/
//find-the-two-repeating-elements-in-a-given-array
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,t;
    int arr[100005];
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=0;i<n+2;i++){
            cin>>arr[i];
        }
        for(int i=0;i<n+2;i++){
            if(arr[abs(arr[i])]>=0){
                arr[abs(arr[i])] = -arr[abs(arr[i])];
            }else{
                cout<<abs(arr[i])<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}
