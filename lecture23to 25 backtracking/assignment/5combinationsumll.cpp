// 40. Combination Sum II
// Medium

// 5732

// 147

// Add to List

// Share
// Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.

// Each number in candidates may only be used once in the combination.

// Note: The solution set must not contain duplicate combinations.

 

// Example 1:

// Input: candidates = [10,1,2,7,6,1,5], target = 8
// Output: 
// [
// [1,1,6],
// [1,2,5],
// [1,7],
// [2,6]
// ]
// Example 2:

// Input: candidates = [2,5,2,1,2], target = 5
// Output: 
// [
// [1,2,2],
// [5]
// ]
class Solution {
public:
    void solve(  vector<vector<int>>&output, vector<int>&temp,vector<int>& candidates, int target,int index){
        if(target ==0){
            output.push_back(temp);
            return;
        }
        if(target<0 || index>=candidates.size()){
            return;
        }
        for(int i=index;i<candidates.size();i++){
            //SPECIAL CONDITION
            if(i>index && candidates[i] == candidates[i-1])
                continue;
            if(candidates[i]> target)
                break;
            
            temp.push_back(candidates[i]); //include call
            
            solve(output,temp,candidates,target-candidates[i],i+1);
            temp.pop_back();
            
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>>output;
        vector<int>temp;
    
        solve(output,temp,candidates, target,0);
        return output;
    }
};