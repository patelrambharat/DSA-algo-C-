#include<bits/stdc++.h>
using namespace std;
int main(){
    int arr[] = {1,2,3,4,5};
    int n = 5;
     int j =0;
       for(int i= 0; i < n; i++){
           arr[j] = arr[i];
           
           j++;
           cout<<arr[i];
       }
       for(int i=0;i<n;i++)
        cout<<arr;
}