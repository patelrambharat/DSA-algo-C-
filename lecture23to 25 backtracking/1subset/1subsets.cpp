// 78. Subsets
// Medium

// 10253

// 157

// Add to List

// Share
// Given an integer array nums of unique elements, return all possible subsets (the power set).

// The solution set must not contain duplicate subsets. Return the solution in any order.

 

// Example 1:

// Input: nums = [1,2,3]
// Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
// Example 2:

// Input: nums = [0]
// Output: [[],[0]]

//include and exclude game


class Solution {
public:
    void solve(  vector<int>& nums,vector<vector<int>>&ans,vector<int>output,int index){
        if(index >= nums.size()){
            ans.push_back(output);
            return;
        }
        
        //exclude
        solve(nums,ans,output,index+1);
        
        //include
        int ele = nums[index];
        output.push_back(ele);
        solve(nums,ans,output,index+1);
       
        
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>output;
        int index =0;
        solve(nums,ans,output,index);
        return ans;
    }
};