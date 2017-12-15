//heap
#include<iostream>
using namespace std;
void maxheapify(int arr[], int n,int i){
    int left = 2*i;
    int right = 2*i +1;
    int largest;
    if(left<=n && arr[left] > arr[i]) largest = left;
    else largest = i;
    if(right <= n && arr[right] > arr[largest]) largest = right;
    if(largest != i){
        swap(arr[i],arr[largest]);
        maxheapify(arr,n,largest);
    }
}
void buildheap(int arr[], int n){
    for(int i=n/2;i>=1;i--){
        maxheapify(arr,n,i);
    }
}
void heapsort(int arr[], int n){
    int heapsize = n;
    for(int i=n;i>=2;i--){
        swap(arr[1],arr[i]);
        heapsize--;
        maxheapify(arr,heapsize,1);
    }
}
int main(){
    int n;
    cin>>n;
    int arr[1005];
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    buildheap(arr,n);
    heapsort(arr,n);
    for(int i=1;i<=n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}
