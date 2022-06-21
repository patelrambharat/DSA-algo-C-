// Move all negative numbers to beginning and positive to end with constant extra space

// Difficulty Level : Easy
// Last Updated : 14 Jun, 2022
// An array contains both positive and negative numbers in random order. Rearrange the array elements so that all negative numbers appear before all positive numbers.

// Examples : 

// Input: -12, 11, -13, -5, 6, -7, 5, -3, -6
// Output: -12 -13 -5 -7 -3 -6 11 6 5


#include<iostream>
using namespace std;
int main(){
    int arr[] = {-12, 11, -13, -5, 6, -7, 5, -3, -6};
    int n= 9;
    int j=0;
    for(int i=0;i<n;i++){
    if(arr[i]<0){
        if(i != j){
            swap(arr[i],arr[j]);
            j++;
        }
    }

    
}
for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}