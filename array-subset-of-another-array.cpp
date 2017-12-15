//
//array-subset-of-another-array
#include<iostream>
#include<set>
using namespace std;
int main(){
    int n,m,t;
    cin>>t;
    while(t--){
        cin>>m>>n;
        int x;
        set<int> st;
        for(int i=0;i<m;i++){
            cin>>x;
            st.insert(x);
        }
        int flag = 0;
        for(int i=0;i<n;i++){
            cin>>x;
            if(flag == 0 && st.find(x) == st.end()){
                flag = 1;
            }
        }
        (flag==1)?(cout<<"No\n"):(cout<<"Yes\n");
    }
    return 0;
}
