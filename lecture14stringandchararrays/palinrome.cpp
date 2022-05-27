#include<iostream>
using namespace std;

bool isValid(char ch){
    if(ch >='a' && ch <= 'z' || ch >='A' && ch <= 'Z' || ch >='0' && ch <= '9'){
        return true;
    }
    else {
        return false; //special or other case number
    }
}
char toLowerCase(char ch){
   if(ch >='a' && ch <= 'z' || ch >='0' && ch <= '9'){
       return ch;       //if all are small then return it
   }
   else{
       return (ch-'A'+'a');  //convert upper letter to lower case
   }
}
bool checkIfPalindrome(string s){
    int start =0;
    int end = s.size()-1;
    while(start <= end){
        if(!isValid(s[start])){
            start++;
        }
        else if(!isValid(s[end])){
            end--;
        }
        else{
            if(toLowerCase(s[start]) != toLowerCase(s[end])){
                return false;
            }
            else{
                start++;
                end--;
            }
        }
    }
    return true;
}
int main(){
    string str = "codingninjassajNiNgNidoc";
    cout<<checkIfPalindrome(str);
   
}