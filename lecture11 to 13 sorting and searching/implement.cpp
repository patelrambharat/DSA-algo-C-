#include<iostream>
using namespace std;

bool binarysearch(int arr[],int n,int target){
    int s = 0;
    int e = 0;
    int mid = s+(e-s)/2;
    while(s<=e){
            if(arr[mid]==target){
                return true;
            }
            if(arr[mid] < target){
                s = mid+1;
            }
            if(arr[mid] > target){
                e = mid-1;
            }
            mid = s+(e-s)/2;
    }
}
int main(){
    int arr[] ={2,3,4,5,6,8};
    int target =1;
    cout<<binarysearch(arr,6,target);
}