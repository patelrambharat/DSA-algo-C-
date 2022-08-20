```
#include<iostream>
#include<vector>
using namespace std;


int solveRec(int n ) {
    //base case
    if(n == 0)
        return 0;
    if(n == 1)
        return 1;

    //Rec relation
    int ans = solveRec(n-1) + solveRec(n-2);
    return ans;
}

int solveRec(int n) {
    //base case
    if(n== 1232) {
        return 123;
    }

    int ans = solveRec(12)  -solveRec(1242);
    return ans;;
}


//Recursion
int solve(int n) {
    //base case
    if(n == 0)
        return 0;
    if(n == 1)
        return 1;
    
    int ans = solve(n-1) + solve(n-2);
    return ans;
}

//Rec + Mem
//step1: create dp array + pass in function
//step2: store the ans in dp array
//step3: check if dp array already has answer, if yes, then return. Just after the base case
int solveMem(int n, vector<int>& dp) {
    //base case
    if(n == 0)
        return 0;
    if(n == 1)
        return 1; 
    //step3 
    if(dp[n] != -1) {
        return dp[n];
    }
    
    int ans = solveMem(n-1, dp) + solveMem(n-2, dp);

    //step2
    return dp[n] = ans;
}

//Bottom-Up approach
//Step1: dp array creation
//step2: Base case analysis of Rec code and update dp array accordingly
//step3: find the range for the changing variable and copy paste the logic in rec code accoprdingly
int solveTab(int nthTerm) {

    //step1: createa DP array
    vector<int> dp(nthTerm+1, 0);

    //step2: update DP array, basis on Recursion Base case
    dp[0] = 0;
    dp[1] = 1;

    //step3: find range and copy paste
    for(int n=2; n<=nthTerm; n++) {
        int ans = dp[n-1] + dp[n-2];
        dp[n] = ans;
    }
    return dp[nthTerm];
}

int solveTabSO(int nthTerm) {
    //step1: replace dp array with your optimised storage strcutures && remove dp array creation and updation part
    int prev1 = 1;
    int prev2 = 0;
    int curr;

    //step2: dp values -> replace -> prev1, prev2
    for(int n=2; n<=nthTerm; n++) {
        int ans = prev1 + prev2;
        curr = ans;
        //step3: take care of the movement and updation of prev1, prev2
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}

int main() {

    int n;
    cout << "Enter the value of n " << endl;
    cin >> n;

    //step1:
    // vector<int> dp(n+1, -1);
    // int ans = solveMem(n, dp);

    cout << "ans is -> " << solveRec(n) << endl;




    return 0;
}
```