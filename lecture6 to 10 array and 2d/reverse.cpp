#include <bits/stdc++.h>
using namespace std;


void reversearr(int arr[],int n){
    int start = 0;
    int high = n-1;
    while(start<=high){
        swap(arr[start],arr[high]);
        start++;
        high--;
    }


}
void printArray(int arr[], int size)
{
   for (int i = 0; i < size; i++)
   cout << arr[i] << " ";

   cout << endl;
}

int main(){
     int arr[] = {1, 2, 3, 4, 5, 6};
      int n = sizeof(arr) / sizeof(arr[0]);
      reversearr(arr,n);
printArray(arr,n);
}
