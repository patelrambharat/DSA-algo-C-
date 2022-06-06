#include<iostream>
using namespace std;
// ///Power Set: Power set P(S) of a set S is the set of all subsets of S. For example S = {a, b, c} then P(s) = {{}, {a}, {b}, {c}, {a,b}, {a, c}, {b, c}, {a, b, c}}.
// If S has n elements in it then P(s) will have 2n elements
void printpowerset(string str,int index,string output){

    if(index==str.length()){
            cout<<output<<endl;
            return;


    }
    //exclude
    printpowerset(str,index+1,output);   //string ko bs aage badhate hai

    //include
    char ch = str[index];
    output.push_back(ch);
    printpowerset(str,index+1,output);

}
int main(){

    string str;
    cout<<"enter the string "<<endl;
    cin>>str;
    string output="";
    printpowerset(str,0,output);
    return 0;
}