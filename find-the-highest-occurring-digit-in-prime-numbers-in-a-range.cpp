//
//find-the-highest-occurring-digit-in-prime-numbers-in-a-range
#include<iostream>
#include<climits>
using namespace std;
int prime[1000005];
int range = 1000005;
void seive(){
    prime[0] = 1;
    prime[1] = 1;
    for(int p=2;p*p<=range;p++){
        if(prime[p]==0){
            for(int i=p*2;i<=range;i+=p){
                prime[i]=1;
            }
        }
    }
}
int main(){
    int t,l,r;
    cin>>t;
    int count[10];
    seive();
    // for(int i=0;i<50;i++){
    //     if(prime[i]==0) cout<<i<<" ";
    // }
    // cout<<endl;
    while(t--){
        for(int i=0;i<10;i++){
            count[i] = 0;
        }
        cin>>l>>r;
        int flag = 0;
        for(int i=l;i<=r;i++){
            if(prime[i] == 0){
                flag=1;
                int temp = i;
                while(temp>0){
                    int rem = temp%10;
                    count[rem]+=1;
                    temp/=10;
                }
            }
        }
        int max= -INT_MAX;
        int ans;
        for(int i=1;i<10;i++){
            if(count[i]>=max){
                max=count[i];
                ans = i;
            }
        }
        (flag==1)?(cout<<ans<<endl):(cout<<"-1\n");
    }
    return 0;
}
