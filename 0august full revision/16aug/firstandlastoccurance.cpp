#include<iostream>
using namespace std;

int firstoccurance(int arr[] , int n, int target){
    int start =0;
    int end = n-1;
    int ans =-1;
    while(start <= end){
        int mid = (start + end)/2;
        if(arr[mid]==target){
            ans = mid;
            end = mid -1;
        }
        else if(arr[mid] > target){
            end = mid -1;
        }
        else {
            start = mid +1;
        }
    }
}
int lastoccurance(int arr[], int n, int target){
    int start =0;
    int end =n-1;
    int ans =-1;
    while(start <= end){
        int mid = (start + end)/2;
        if(arr[mid] == target){
            ans = mid;
            start = mid+1;
        }
        else if(arr[mid] > target){
            end = mid -1;
        }
        else {
            start = mid+1;
        }
    }
}


int totaloccurance(int arr[], int n, int  target){
    int total = lastoccurance(arr, n, target) - firstoccurance(arr, n, target);
    return total;
}
int main(){
    int arr[] = {1,2,3, 4,5,5,5,5,5,5,6,8 ,9};  
    int n = 13;
    int target = 5;
    cout<<firstoccurance(arr,n, target)<<endl;
    cout<<lastoccurance(arr, n, target)<<endl;
    cout<<totaloccurance(arr, n, target)<<endl;
}