#include<iostream>
using namespace std;

int ncr(int n,int r){
int val1= fact(n);
int val2 = fact(n-r);
int val3= fact(r);

int ans = val1/(val2*val3);
return ans;

}
int fact(int n){
int ans =1 ;
for(int i=n ;i>=1;i--){
    ans = n *i;
}
return ans;

}
int main(){

cout<<ncr(row,col)<<" ";
}
