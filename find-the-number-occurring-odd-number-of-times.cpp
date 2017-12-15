//http://www.geeksforgeeks.org/find-the-number-occurring-odd-number-of-times/
//find-the-number-occurring-odd-number-of-times
#include<bits/stdc++.h>
using namespace std;
int main(){
    int t,n;
    int arr[1001];
    cin>>t;
    while(t--){
        cin>>n;
        int xr = 0;
        for(int i=0;i<n;i++){
            cin>>arr[i];
            xr = xr ^ arr[i];
        }
        cout<<xr<<endl;
    }
    return 0;
}
