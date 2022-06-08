// 40. Combination Sum II
// Medium

// 5482

// 145

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


//------------------------condition to handle with duplicate--------------//

class Solution {
public:
    void solve(vector<int>& candidates, int target, vector<vector<int>> &output,
               vector<int> &temp, int index) {
        //base case
        if(target == 0 ) {
            //ans store
            output.push_back(temp);
            return ;
        }
        
        if(target < 0 || index >= candidates.size()) 
            return;
        
        for(int i = index; i < candidates.size(); i++) {
            
            //special condition
            if(i > index && candidates[i] == candidates[i-1])
                continue;
            
            if(candidates[i] > target)
                break;
            
            temp.push_back(candidates[i]);
            solve(candidates, target-candidates[i], output, temp, i+1);
            temp.pop_back();
            
        }
        
       
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        
        vector<vector<int>> output;
        vector<int> temp;
        
        solve(candidates, target, output, temp, 0);
        return output;
        
    }
};