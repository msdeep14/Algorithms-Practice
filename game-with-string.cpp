//
//game-with-string
#include<iostream>
#include<string>
#include<algorithm>
#include<queue>
using namespace std;
int main(){
    int t,k;
    cin>>t;
    while(t--){
        priority_queue<int> p;
        string s;
        cin>>s;
        cin>>k;
        int arr[26];
        for(int i=0;i<26;i++) arr[i]=0;
        for(int i=0;i<s.length();i++){
            //cout<<(s[i]-48)<<" ";
            arr[s[i]-97] +=1;
        }
        for(int i=0;i<26;i++){
            if(arr[i] != 0){
                p.push(arr[i]);
            }
        }
        while(k--){
            int x = p.top();
            x-=1;
            p.pop();
            p.push(x);
        }
        int sum =0;
        while(!p.empty()){
            int y = p.top();
            sum+= y*y;
            p.pop();
        }
        //cout<<endl;
        // sort(arr,arr+26);
        // for(int i=0;i<26;i++)cout<<arr[i]<<" ";
        // cout<<endl;
        // int j=25;
        // for(int i=0;i<k;i++){
        //     if(arr[j]>0 && arr[j]>=arr[j-1]){
        //         arr[j]-=1;
        //     }else{
        //         j--;
        //         if(j<1 && i<k){
        //             j=25;
        //         }
        //     }
        // }
        // for(int i=0;i<26;i++){
        //     sum += arr[i]*arr[i];
        // }
        cout<<sum<<endl;
    }
    return 0;
}
