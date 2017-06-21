//
//n-divisors
#include<iostream>
using namespace std;
int prime[1000005];
int r = 1000005;
void seive(){
    prime[0] = 1;
    prime[1] = 1;
    for(int p=2;p*p<=r;p++){
        if(prime[p] == 0){
            for(int i=p*2;i<=r;i+=p){
                prime[i] = 1;
            }
        }
    }
}
int main(){
    int t,a,b,n;
    cin>>t;
    seive();
    while(t--){
        cin>>a>>b>>n;
        for(int i=a;i<=b;i++){
            int temp = 1;
            int x = 0;
            int y = 2;
            for(int j=2;j<=sqrt(i);j+=x){
                if(prime[j] == 0){
                    if(i%y == 0){
                        temp=temp*j;
                        y=temp;
                        x=0;
                    }
                }else{
                    y=j+1;
                    x=1;
                }
            }
        }
    }
    return 0;
}
