#include<iostream>
using namespace std;
bool palindrome(int arr[], int n){
    int i=0;
    int j= n-1;
    while(i< j){
            if(arr[i] != arr[j]){
                return false;
            }
            else{
                return true;
            }
    }
}
int main(){
int arr[] = {1,2,3,3,2,0};
int n = 6;
cout<<palindrome(arr, n);
// for(int i=0;i< n;i++){
//     cout<<arr[i]<<" ";
// }
}