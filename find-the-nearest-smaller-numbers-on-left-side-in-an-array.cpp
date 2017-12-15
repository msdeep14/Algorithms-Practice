// http://www.geeksforgeeks.org/find-the-nearest-smaller-numbers-on-left-side-in-an-array/
#include <bits/stdc++.h>
using namespace std;
int main(){
    int t,n;
    int arr[1001];
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        stack<int> s;
        for(int i=0;i<n;i++){
            if(s.empty()){
                cout<<"-1 ";

            }
            else{
                int x = s.top();
                if(x < arr[i]){
                    cout<<x<<" ";
                    //s.pop();
                    //s.push(arr[i]);
                }else{
                    
                }
            }
            s.push(arr[i]);
        }
    }
}
