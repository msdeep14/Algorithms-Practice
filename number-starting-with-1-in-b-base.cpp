//http://practice.geeksforgeeks.org/problems/number-starting-with-1-in-b-base/0
//number-starting-with-1-in-b-base
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
    int t,b;
    cin>>t;
    while(t--){
        int n;
        cin>>n>>b;
        int m = log2(n);
        int flag=0;
        for(int i=1;i<=m;i++){
            if(n>=pow(b,i) && n<=2*pow(b,i)-1){
                cout<<"Yes\n";
                flag=1;
                break;
            }
        }
        if(flag==0)cout<<"No\n";
    }
    return 0;
}
