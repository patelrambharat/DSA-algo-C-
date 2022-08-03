// #include<iostream>
// using namespace std;
// int main(){
//     int num = 1010;
//     int product =1;
//     int decimal =0;
//     while(num != 0){
//         int rem = num % 10;
//         decimal = decimal + rem * product;
//         num = num /10;
//         product = product *2;
//     }
//     cout<<decimal<<endl;
// }
#include<iostream>
#include<math.h>
using namespace std;
int main(){
    int num = 1011;
    int ans =0;
    int i=0;
    while(num != 0){
        int bit = num % 10;
        ans = (bit * pow(2, i))+ ans;
        num = num / 10;
        i++;
    }
    cout<<ans<<endl;
}