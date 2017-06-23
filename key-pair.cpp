//
//http://practice.geeksforgeeks.org/problems/key-pair/0
#include<bits/stdc++.h>
using namespace std;
int main(){
    int t,n,x;
    cin>>t;
    while(t--){
        cin>>n>>x;
        int arr[205];
        set<int> s;
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        int flag=0;
        for(int i=0;i<n;i++){
            int y = x-arr[i];
            if(s.find(y) != s.end()){
                flag=1;
                break;
            }else{
                s.insert(arr[i]);
            }
        }
        (flag==1)?(cout<<"Yes\n"):(cout<<"No\n");
        s.clear();
    }
    return 0;
}
