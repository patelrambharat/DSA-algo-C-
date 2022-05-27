#include<bits/stdc++.h>
using namespace std;

void sort012(int arr[],int n){
    int low =0;
    int high = n;
    int mid =0;
    while(mid<=high){
        if(arr[mid]==0){
            swap(arr[mid],arr[low]);
            low++;
            mid++;
        }
        else if(arr[mid]==1){
            mid++;
        }
        else {
            swap(arr[mid],arr[high]);

            high--;
        }
    }

}

void printarray(int arr[],int n){
    for(int i=0;i<=n;i++){
        cout<<arr[i]<<" ";
    }
}
int main(){
int arr[] = {0,2,2,1,0,2,1,2,0};
int n = sizeof(arr)/sizeof(arr[0]);

sort012(arr,n);
printarray(arr,n);
}
