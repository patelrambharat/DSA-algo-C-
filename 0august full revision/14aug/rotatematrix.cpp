#include<iostream>
using namespace std;
void rotate_matrix(int arr[4][4]){
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            swap(arr[i][j] , arr[j][i]);
        }
    }
    for(int i=0;i<4;i++){
        int start =0, end = 4-1;
        while(start<end){
            swap(arr[i][start], arr[i][end]);
        }
    }
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            cout<<arr[i][j]<<" ";
        }
    }
}
int main(){
    int i,j;
    // int arr[4][4];
 
    // Get the matrix elements
    int arr[4][4] = { {1, 1, 1, 1}, 
                       {2, 2, 2, 2}, 
                       {3, 3, 3, 3}, 
                       {4, 4, 4, 4}};
 
    // Get each row sum
    // printrowsum(arr);
    rotate_matrix(arr);
}