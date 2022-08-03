// #include<iostream>
// #include<math.h>
// using namespace std;
// int main(){
//     int num = 10;
//     int binary = 0;
//     int product =1;
//     while(num != 0){
//         int rem = num % 2;
//         binary = binary + rem * product;
//         num = num /2;
//         product = product *10;
//     }
//     cout<<binary<<endl;
// }= 
#include<iostream>
#include<math.h>
using namespace std;
int main(){
    int num = 11;
    int i= 0;
    int ans  =0 ;
    while(num !=0){
        int bit = num & 1;
       ans = (bit * pow(10,i)) + ans;
        num = num >> 1;
        i++;
    }
    cout<<ans<<endl;
}