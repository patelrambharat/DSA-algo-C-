#include<iostream>
using namespace std;
int negative(int arr[] , int n){
    int j=0;
    for(int i=0;i< n;i++){
        if(arr[i] < 0){
            swap(arr[i] , arr[j]);


            j++;
        } 
    }
}
int main(){
    int arr[] = {3, -1, 2, -4, -6, -4, 5};
    int n = 7;
    negative(arr, n);
    for(int i=0;i< n;i++){
        cout<<arr[i]<<" " ;
    }
}