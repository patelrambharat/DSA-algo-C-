#include<iostream>
using namespace std;
int squareRoot(int num){
    int start =0;
    int end = num;
    int ans = -1;
    while(start <= end){
        int mid = (start + end)/2;
        if(mid*mid == num){
            return mid;
        }
        else if(mid * mid < num){
             ans = mid;
            start = mid +1;
           
        }
        else{
            end = mid -1;
        }
    }
    return ans;
}
int main(){
    int n= 29;
    cout<<squareRoot(n)<<endl;
}

//for decimal value 