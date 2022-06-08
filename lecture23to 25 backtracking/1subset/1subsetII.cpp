90. Subsets II
Medium

5302

156

Add to List

Share
Given an integer array nums that may contain duplicates, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

 

Example 1:

Input: nums = [1,2,2]
Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
Example 2:

Input: nums = [0]
Output: [[],[0]]

class Solution {
public:
   void recur(int idx,vector<int>&nums,vector<int>val,vector<vector<int>>&ans){

    ans.push_back(val);
        
    for(int i=idx;i<nums.size();i++){
        
        if(i!=idx && nums[i]==nums[i-1]) continue;   // To avoid duplicate entries 
		//[2,2] -> [2,pos->0],[2,pos->1] NOT OK || Chosing Either is a Solution
        val.push_back(nums[i]);
        recur(i+1,nums,val,ans);
        val.pop_back();    //Backtracking
    }
   
   
    
}
vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    
	//Time Complexity ->O(2^n)*O(n)  || O(n)-->To push into ans
	//Space Complexity -> O(2^n)*O(k) || O(k)-->Average Length of Subarrays
	//Auxillary Complexity ->O(n) -->Recursive Stack can go only upto height of the tree
	
    sort(nums.begin(),nums.end());  //Done to avoid duplicate entries
    vector<vector<int>>ans;
    vector<int>val;
    recur(0,nums,val,ans);
    return ans;
   
}
};
