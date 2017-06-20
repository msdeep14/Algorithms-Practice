//
//sum-of-product-of-all-pairs
#include <iostream>
using namespace std;
int main(){
    int t,n;
    int arr[105];
    cin>>t;
    while(t--){
        int sum = 0;
        int sqsum = 0;
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>arr[i];    
        }
        for(int i=0;i<n;i++){
            sum+=arr[i];
            sqsum += arr[i]*arr[i];
        }
        /*for(int i=0;i<n-1;i++){
            for(int j = i+1;j<n;j++){
                sum+=arr[i]*arr[j];
            }
        }*/

        //way2
        int res = (sum*sum - sqsum)/2;
        cout<<res<<endl;
    }
    return 0;
}
