#include<iostream>
using namespace std;


void findSequences(int leftsum ,int rightsum , char* output,int i,int j){
    //base case 
    if(i>j){
        if(leftsum == rightsum){
        cout<<output<<endl;
        }
        return;
        
    }
    //put 0,0

    output[i] ='0';
    output[j] ='0';
    findSequences(leftsum,rightsum,output,i+1,j-1);
    //put 0,1
     output[i] ='0';
    output[j] ='1';
    findSequences(leftsum,rightsum+1,output,i+1,j-1);
    //put 1,0
     output[i] ='1';
    output[j] ='0';
    findSequences(leftsum+1,rightsum,output,i+1,j-1);
    //put 1,1
     output[i] ='1';
    output[j] ='1';
    findSequences(leftsum+1,rightsum+1,output,i+1,j-1);
}
int main(){

    cout<<"Enter the value of n"<<endl;
    int n;
    cin>>n;
    char* arr = new char[2*n];
    findSequences(0,0,arr,0,2*n-1);


}