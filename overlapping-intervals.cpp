//http://practice.geeksforgeeks.org/problems/overlapping-intervals/0
//
#include<bits/stdc++.h>
using namespace std;
int main(){
    int t,n;
    int arr[10005];
    cin>>t;
    while(t--){
        cin>>n;
        int x,y;
        vector<pair<int,int> >v;
        for(int i=0;i<n;i++){
            cin>>x>>y;
            v.push_back(make_pair(x,y));
        }
        sort(v.begin(),v.end());
        for(int i=1;i<v.size();i++){
            if(v[i-1].second > v[i].first && v[i-1].second > v[i].second){
                v.erase(v.begin()+i);
            }else if(v[i-1].second > v[i].first && v[i-1].second < v[i].second){
                v[i-1].second = v[i].second;
                v.erase(v.begin() + i);
            }
        }
        for(int i=0;i<v.size();i++){
            cout<<v[i].first<<" "<<v[i].second<<" ";
        }
        cout<<endl;
    }
    return 0;
}
