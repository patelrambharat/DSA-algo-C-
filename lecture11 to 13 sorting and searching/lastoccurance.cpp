#include<iostream>
using namespace std;

int  binarysearch(int arr[],int n,int target){
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
    int arr[] ={0,1,2,3,3,3,4,5,6,8};
    int target =3;
    cout<<binarysearch(arr,11,target);
}