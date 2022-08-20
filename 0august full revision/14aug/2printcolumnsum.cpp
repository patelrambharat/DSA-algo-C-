#include<iostream>
#include<limits.h>
using namespace std;
void printrowsum(int arr[4][4]){
    int i, j, sum =0;
    int maxi = INT_MIN;
    cout<<"finding sum of each row "<<endl;
    for(i=0;i< 4;i++){
        for(j=0;j<4;j++){
            sum = sum + arr[i][j];
            maxi = max(maxi , sum);
        }
        cout<<"sum of the row"<<i <<"and sum is"<<sum<<endl;
        
        //reset the sum
        sum =0;
    }
    cout<<"maximum sum is "<<maxi<<endl;
}
void printcolsum(int arr[4][4]){
    int i, j, sum  =0;
    
    cout<<"finding col sum"<<endl;
    for(i=0;i< 4;i++){
        for(j=0;j<4;j++){
            sum += arr[j][i];

        }
        cout<<"sum of the col"<<j<<" and sum is "<< sum <<endl;
        //reset the sum 
        sum =0;
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
    printrowsum(arr);
    printcolsum(arr);
}