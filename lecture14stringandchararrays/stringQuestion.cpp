#include<iostream>
using namespace std;




//check palindrome

void reverseString(string& s){
    int start =0;
    int end =s.size()-1;
    while(start<=end){
        swap(s[start],s[end]);
        start++;
        end--;
    }
}
int main(){
          string str = "geeksforgeeks";
            reverseString(str);
            cout << str;
            return 0;
}