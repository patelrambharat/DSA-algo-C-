// 77. Combinations
// Medium

// 4302

// 150

// Add to List

// Share
// Given two integers n and k, return all possible combinations of k numbers out of the range [1, n].

// You may return the answer in any order.

 

// Example 1:

// Input: n = 4, k = 2
// Output:
// [
//   [2,4],
//   [3,4],
//   [2,3],
//   [1,2],
//   [1,3],
//   [1,4],
// ]
// Example 2:

// Input: n = 1, k = 1
// Output: [[1]]

//aproach same as exclude include -----------------

class Solution {
public:
     void solve(int idx,int n,int k, vector<vector<int>>&ans,vector<int>&present) {
         if(k==present.size()){
             ans.push_back(present);
             return;
         }
         if(idx> n){
             return;
         }
         //exclude 
         solve(idx+1,n,k,ans,present);
        //include
         present.push_back(idx);
         solve(idx+1,n,k,ans,present);   //recursive call
         present.pop_back();  //backtracking
         
     }
    vector<vector<int>> combine(int n, int k) {
         vector<vector<int>> ans;
            vector<int>present;
              solve(1,n,k,ans,present);
        
        return ans;
    }
};