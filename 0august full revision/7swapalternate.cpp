#include<iostream>
using namespace std;
int main(){
    int arr[] = {2,7,8,3,4,5,24,5,3};
    int n = 9;
    for(int i=0;i<n;i += 2){
        if(i+1 < n)
            swap(arr[i] , arr[i+1]);
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}