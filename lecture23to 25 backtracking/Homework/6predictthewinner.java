// 486. Predict the Winner
// Medium

// 2992

// 153

// Add to List

// Share
// You are given an integer array nums. Two players are playing a game with this array: player 1 and player 2.

// Player 1 and player 2 take turns, with player 1 starting first. Both players start the game with a score of 0. At each turn, the player takes one of the numbers from either end of the array (i.e., nums[0] or nums[nums.length - 1]) which reduces the size of the array by 1. The player adds the chosen number to their score. The game ends when there are no more elements in the array.

// Return true if Player 1 can win the game. If the scores of both players are equal, then player 1 is still the winner, and you should also return true. You may assume that both players are playing optimally.

 

// Example 1:

// Input: nums = [1,5,2]
// Output: false
// Explanation: Initially, player 1 can choose between 1 and 2. 
// If he chooses 2 (or 1), then player 2 can choose from 1 (or 2) and 5. If player 2 chooses 5, then player 1 will be left with 1 (or 2). 
// So, final score of player 1 is 1 + 2 = 3, and player 2 is 5. 
// Hence, player 1 will never be the winner and you need to return false.
// Example 2:

// Input: nums = [1,5,233,7]
// Output: true
// Explanation: Player 1 first chooses 1. Then player 2 has to choose between 5 and 7. No matter which number player 2 choose, player 1 can choose 233.
// Finally, player 1 has more score (234) than player 2 (12), so you need to return True representing player1 can win.

// So assuming the sum of the array it SUM, so eventually player1 and player2 will split the SUM between themselves. For player1 to win, he/she has to get more than what player2 gets. If we think from the prospective of one player, then what he/she gains each time is a plus, while, what the other player gains each time is a minus. Eventually if player1 can have a >0 total, player1 can win.
// Helper function simulate this process. In each round:
// if e==s, there is no choice but have to select nums[s]
// otherwise, this current player has 2 options:
// --> nums[s]-helper(nums,s+1,e): this player select the front item, leaving the other player a choice from s+1 to e
// --> nums[e]-helper(nums,s,e-1): this player select the tail item, leaving the other player a choice from s to e-1
// Then take the max of these two options as this player's selection, return it.

public class Solution {
    public boolean PredictTheWinner(int[] nums) {
        return helper(nums, 0, nums.length-1)>=0;
    }
    private int helper(int[] nums, int s, int e){        
        return s==e ? nums[e] : Math.max(nums[e] - helper(nums, s, e-1), nums[s] - helper(nums, s+1, e));
    }
}


//cpp approach
class Solution {
public:
    int helper(vector<int>nums,int s,int e){
        if(s==e){
            return nums[e];  //there is no choice but have to select nums[s]
        }
        else{  //otherwise 2 option
            // --> nums[s]-helper(nums,s+1,e): this player select the front item, leaving the other player a choice from s+1 to e
// --> nums[e]-helper(nums,s,e-1): this player select the tail item, leaving the other player a choice from s to e-1
            return max(nums[e]-helper(nums,s,e-1),nums[s]-helper(nums,s+1,e));
        }
    }
    bool PredictTheWinner(vector<int>& nums) {
        return helper(nums,0,nums.size()-1)>=0;
    }
};