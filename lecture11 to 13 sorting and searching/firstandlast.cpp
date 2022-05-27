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
    vector<int>&arr ={0,1,2,3,3,3,4,5,6,8};
    int n =11;
    int target =3;
    if(n ==0){
        return {-1 , -1};
    }
    int upper = upper_index(arr,n,target);
    int lower = lower_index(arr,n,target);
    return {upper,lower};
}