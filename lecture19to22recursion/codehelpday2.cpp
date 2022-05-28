#include<iostream>
using namespace std;


//say digit like 123 =="one two three"

int sayDigit(int n,string arr[]){
    if(n==0){
        return 0;
    }
    //processing 
    int digit = n%10;
    n=n/10;
   
    sayDigit(n,arr);
     cout<<arr[digit]<<" ";
}
//count ways to reach the n-th stairs
int countDisrictWayToClimb(long long nStairs){
    //base case
    if(nStairs<0){
        return 0;
    }
    if(nStairs==0){
        return 1;
    }
    int ans = countDisrictWayToClimb(nStairs-1) + countDisrictWayToClimb(nStairs-2);
    return ans;
}

//print fibonacci number

int  printFib(int n){
    if(n==0)
        return 0;
    if(n==1)
        return 1;
    return printFib(n-1) + printFib(n-2);
    
}
void reachHome(int src,int dest){
    cout<<" source " <<src<<" and "<<" destination "<<dest<<endl;

    if(src == dest){
        cout<<"pahuch gya";
        return;
    }

    //processing ek-step aage badh jao
    src++; 
    //recursive call
    reachHome(src,dest);
}
int main(){
    // int dest =10;
    // int src =1;
    // reachHome(src,dest);
    // int n= 2;
    // // cout<<printFib(n);
    // cout<<countDisrictWayToClimb(n);

    string arr[10] ={"zero","one","two ","three","four","five","six","seven","eight","nine"};
    int n=10;

     sayDigit(n,arr);
}