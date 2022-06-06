#include<iostream>
using namespace std;

bool checkPalindrome(string str,int i,int j){
    if(i>j){
        return true;
    }
    if(str[i] != str[j]){
        return false;
    }
    else{
        //recursive call
        return checkPalindrome(str,i+1,j-1);
    }
}
int main(){
    string str = "abbaw";
    bool ispalindrome =  checkPalindrome(str,0,str.length()-1);
    if(ispalindrome){
        cout<<"it is a palindrome"<<endl;
    }
    else {
        cout<<"it is not a palindrome"<<endl;
    }
}