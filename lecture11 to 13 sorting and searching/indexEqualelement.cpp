#include<iostream>
using namespace std;

int  binarysearch(int arr[],int n){
    int s = 0;
    int e = n-1;
    int mid = s+(e-s)/2;
   
    while(s<=e){
            if(arr[mid]==mid){
               return mid;
            }
            if(arr[mid] < mid){
                s = mid+1;
            }
            if(arr[mid]>mid){
                e = mid-1;
            }
            mid = s+(e-s)/2;
           
    }

    
}
int main(){
    int arr[] ={0,1,2,3,4,5,6,8};
    
    cout<<binarysearch(arr,8);
}