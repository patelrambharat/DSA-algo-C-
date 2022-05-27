#include<bits/stdc++.h>
using namespace std;

void maxmin(int arr[],int n){
    int maxele = arr[0];
    int minele = arr[0];
    for(int i=1;i<n;i++){
        if(minele > arr[i]){
            minele = arr[i];
        }
        if(maxele < arr[i]){
            maxele = arr[i];
        }
    }
    cout<<"maxele " <<maxele<<"minele "<<minele<<" ";
}
int main(){
int arr[] = {9,7,8,4,1,10,5};
int n = sizeof(arr)/sizeof(arr[0]);

    maxmin(arr,n);


}
