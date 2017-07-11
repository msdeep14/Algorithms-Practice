//
#include <bits/stdc++.h>
using namespace std;
int LongestAP(int arr[], int n){
    unordered_map <int, vector<pair<int,int> > > mp;
    int lengthStore[1000];
    for(int i=0; i<n;i++){
        for(int j=i+1;j<n;j++){
            int diff = arr[j] - arr[i];
            if(mp.find(diff) == mp.end()){
                vector<pair<int,int> > temp;
                temp.push_back(make_pair(i,j));
                mp.insert(make_pair(diff,temp));
                temp.clear();
            }else{
                // key already present
                vector<pair<int,int> > temp(mp[diff]);
                temp.push_back(make_pair(i,j));
                mp[diff] = temp;
                temp.clear();
            }
        }
    }
    //initialize lengthStore arr with value = 1
    for(int i=0;i<n;i++){
        lengthStore[i] = 1;
    }
    unordered_map <int, vector<pair<int,int> > > :: iterator it;
    // for(it = mp.begin();it!=mp.end();it++){
    //     cout<<it->first<<endl;
    //     vector<pair<int,int> > temp(it->second);
    //     for(int i=0;i<temp.size();i++){
    //         cout<<"("<<temp[i].first<<", "<<temp[i].second<<"),";
    //         //lengthStore[temp[i].second] = lengthStore[temp[i].first] + 1;
    //     }
    //     cout<<endl;
    // }
    for(it = mp.begin(); it!=mp.end(); it++){
        vector<pair<int,int> > temp(it->second);
        for(int i=0;i<temp.size();i++){
            //cout<<lengthStore[temp[i].first]<<" "<<lengthStore[temp[i].second]<<endl;
            lengthStore[temp[i].second] = lengthStore[temp[i].first] + 1;
        }
    }
    //calculate max
    // for(int i=0;i<n;i++){
    //     cout<<lengthStore[i]<<" ";
    // }
    // cout<<endl;

    int mx = -INT_MAX;
    for(int i=0;i<n;i++){
        if(mx < lengthStore[i]){
            mx = lengthStore[i];
        }
    }
    return mx;
}
int main(){
    int n;
    int arr[1000];
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int maxCount = LongestAP(arr,n);
    cout<<maxCount<<endl;
    return 0;
}
