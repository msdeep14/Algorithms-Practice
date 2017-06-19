//
//subarray-with-0-sum
#include<iostream>
#include<set>
using namespace std;
int main(){
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        int arr[100005];
        int flag = 0;
        int sum = 0;
        set<int> s;
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        for(int i=0;i<n && flag==0;i++){
            //cin>>arr[i];
            sum += arr[i];
            if(arr[i] == 0 || sum == 0){
                flag=1;
                break;
            }else if(s.find(sum) == s.end()){
                s.insert(sum);
            }else{
                flag = 1;
                break;
            }
        }
        // set<int> :: iterator it;
        // for(it=s.begin();it!=s.end();it++){
        //     cout<<(*it)<<" ";
        // }
        // cout<<endl;
        (flag == 1)?(cout<<"Yes\n"):(cout<<"No\n");
        s.clear();
    }
    return 0;
}
