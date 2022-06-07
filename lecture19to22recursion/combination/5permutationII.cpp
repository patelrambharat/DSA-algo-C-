// 47. Permutations II
// Medium

// 5758

// 100

// Add to List

// Share
// Given a collection of numbers, nums, that might contain duplicates, return all possible unique permutations in any order.

 

// Example 1:

// Input: nums = [1,1,2]
// Output:
// [[1,1,2],
//  [1,2,1],
//  [2,1,1]]
// Example 2:

// Input: nums = [1,2,3]
// Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

class Solution {
public:
    void solve(vector<int>& nums,vector<vector<int>>&ans,int index ){
        if(index >= nums.size()){
            ans.push_back(nums);
            return;
        }
        unordered_set<int>st;
        for(int i=index;i<nums.size();i++){
            //check duplicate 
            if(st.find(nums[i])!=st.end())
                continue;
            
            st.insert(nums[i]);
            swap(nums[index],nums[i]);
            solve(nums,ans,index+1);
            swap(nums[index],nums[i]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>ans;
        int index=0;
        solve(nums,ans,index);
        return ans;
    }
};