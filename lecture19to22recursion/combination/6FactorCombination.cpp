// 254 Factor Combinations - Medium
// Problem:
// Numbers can be regarded as product of its factors. For example,

// 8 = 2 x 2 x 2;
//   = 2 x 4.

// Write a function that takes an integer n and return all possible combinations of its factors.

// Note: 
// You may assume that n is always positive.
// Factors should be greater than 1 and less than n.

// Examples: 
// input: 1
// output: 
// []
// input: 37
// output: 
// []
// input: 12
// output:
//   [
//     [2, 6],
//     [2, 2, 3],
//     [3, 4]
//   ]  
// input: 32
// output:
// [
//   [2, 16],
//   [2, 2, 8],
//   [2, 2, 2, 4],
//   [2, 2, 2, 2, 2],
//   [2, 4, 4],
//   [4, 8]


void process(int start,vector<vector<int>>ans,vector<int>temp,int n){

    if(n==1){
        if(temp.size()>1){
            ans.push_back(temp);
            return;
        }
    }
    for(int i=start;i<n;i++){
        if(n%i==0){
            temp.push_back(i);
            //recursive call
            process(start,ans,temp,n/i);

            //backtracking
            temp.pop_back();
        }
    }
}
vector<vector<int>> getfactor(int n){
    vector<vector<int>>ans;
    vector<int>temp;
    process(2,res,temp,n);

    return ans;

}
