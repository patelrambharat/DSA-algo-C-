#include<iostream>

#include<math.h>
using namespace std;
int main(){
    string str = "my name is bharat";
    int start =0;
    int end = str.length()-1;
    while(start<= end){
        swap(str[start], str[end]);
        start++;
        end--;
    }
    cout<<str<<endl;
}