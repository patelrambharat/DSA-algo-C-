// Odd Game 
// Easy Accuracy: 65.13% Submissions: 788 Points: 2
// Given an array of length N, starting from 1 to N. At each iteration, you remove all elements at odd positions, until only one element is left. Find the last remaining element.

 

// Example 1:

// Input:
// N = 5
// Output:
// 4
// Explanation:
// Initial Array- {1,2,3,4,5}.
// After 1st Iteration- {2,4}.
// After 2nd Interation- {4}
// Threfore, the answer is 4.
// Example 2:

// Input:
// N = 3
// Output:
// 2
// Explanation:
// Initial Array- {1,2,3}.
// After 1st Iteration- {2}.
// Threfore, the answer is 2.

class Solution {
  public:
    long long oddGame(long long N) {
        // code here
        if(N==1){
            return 1;
        }
        return oddGame(N/2)*2;
    }
};