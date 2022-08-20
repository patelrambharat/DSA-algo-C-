#include<iostream>
using namespace std;
int fixedpoint(int arr[] , int n){
        int start =0;
        int end = n - 1;
        while(start < end){
             int mid =(start + end)/2;
             if(arr[mid] == mid){
                return mid;
             }
             if(arr[mid] > mid){
                end = mid-1;
             }
             else {
                start  = mid +1;
             }
        }
}
int main(){
    int arr[] = {-10,-5,0,3,7};
    int n= 5;
    cout<<fixedpoint(arr,n);

}