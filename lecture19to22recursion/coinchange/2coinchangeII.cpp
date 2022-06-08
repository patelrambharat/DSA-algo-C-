// 518. Coin Change 2
// Medium

// 5281

// 104

// Add to List

// Share
// You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

// Return the number of combinations that make up that amount. If that amount of money cannot be made up by any combination of the coins, return 0.

// You may assume that you have an infinite number of each kind of coin.

// The answer is guaranteed to fit into a signed 32-bit integer.

 

// Example 1:

// Input: amount = 5, coins = [1,2,5]
// Output: 4
// Explanation: there are four ways to make up the amount:
// 5=5
// 5=2+2+1
// 5=2+1+1+1
// 5=1+1+1+1+1
// Example 2:

// Input: amount = 3, coins = [2]
// Output: 0
// Explanation: the amount of 3 cannot be made up just with coins of 2.
// Example 3:

// Input: amount = 10, coins = [10]
// Output: 1


//it give tle 

class Solution {
public:
    
        
int solve(vector<int>& coins,int n, int amount, int currentCoin) {
    //base case
    if(amount == 0 )
        return 1;

    if( amount < 0) 
        return 0;

    int ways = 0;

    //use every coin
    for(int i = currentCoin; i<n; i++) {
        ways = solve(coins, n, amount - coins[i], i);
    }    

    return ways;
}
    int change(int amount, vector<int>& coins) {
        return solve(coins,coins.size(),amount,0);
    }
};