#include<iostream>
using namespace std;

// Given an input string of numbers, find all combinations of numbers that can be formed using digits in the same order.
// Examples: 

// Input : 123 
// Output :1 2 3
//         1 23
//         12 3
//         123

// Input : 1234
// Output : 1 2 3 4 
//         1 2 34 
//         1 23 4 
//         1 234 
//         12 3 4 
//         12 34 
//         123 4 
//         1234 

void findCombination(string input ,int i,string output){
    //base case 
    if(i==input.length()){
        cout<<output<<endl;
        return;
    }
    //exclude 
    char ch = input[i];
    //no space put character without space
    output.push_back(ch);
    findCombination(input,i+1,output);

    //with space put character with space   
    output.push_back(' ');
    if(input[i+1] !='\0'){      //if last me null element nhi hai to 
        findCombination(input,i+1,output);
    }
}
int main(){


    string str = "123";
    string output = "";
    int index=0;
    findCombination(str,index,output);

}