#include<iostream>
using namespace std;
int binarysearch(int arr[], int n, int key){
    int start =0;
    int end = n-1;
    while(start<end){
        int mid = (start+end)/2;
        if(arr[mid] ==key ){
            return mid;
        }
        else if(arr[mid] > key){
            end = mid-1;
        }
        else{
            start = mid+1;
        }

    }
}
int main(){
   
    int arr[] = {2,3 ,4,5,8, 9 };
    int key = 8;
    int n = 6;
    cout<<binarysearch(arr,n, key)<<endl;
}