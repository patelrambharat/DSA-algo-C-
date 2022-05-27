#include<bits/stdc++.h>
using namespace std;

int  lower_index(int arr[],int n,int target){
    int s = 0;
    int e = n-1;
    int mid = s+(e-s)/2;
    int ans =-1;
    while(s<=e){
            if(arr[mid]==target){
                ans = mid;
                e = mid -1;
            }
            if(arr[mid] < target){
                s = mid+1;
            }
            if(arr[mid]>target){
                e = mid-1;
            }
            mid = s+(e-s)/2;
           
    }
     return ans;
    
}
int  upper_index(int arr[],int n,int target){
    int s = 0;
    int e = n-1;
    int mid = s+(e-s)/2;
    int ans =-1;
    while(s<=e){
            if(arr[mid]==target){
                ans = mid;
                s = mid +1;
            }
            if(arr[mid] < target){
                s = mid+1;
            }
            if(arr[mid]>target){
                e = mid-1;
            }
            mid = s+(e-s)/2;
           
    }
     return ans;
    
}
int main(){
    int arr[] ={0,1,2,3,3,3,3,4,5,6,8};
    int n =12;
    int target =3;
   int lower = lower_index(arr,n,target);
    int upper = upper_index(arr,n,target);
    int total = upper - lower +1;
    cout<<total<<" ";
}