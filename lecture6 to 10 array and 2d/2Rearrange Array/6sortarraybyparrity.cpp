// 922. Sort Array By Parity II
// Easy

// 1824

// 72

// Add to List

// Share
// Given an array of integers nums, half of the integers in nums are odd, and the other half are even.

// Sort the array so that whenever nums[i] is odd, i is odd, and whenever nums[i] is even, i is even.

// Return any answer array that satisfies this condition.

 

// Example 1:

// Input: nums = [4,2,5,7]
// Output: [4,5,2,7]
// Explanation: [4,7,2,5], [2,5,4,7], [2,7,4,5] would also have been accepted.
// Example 2:

// Input: nums = [2,3]
// Output: [2,3]
class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        vector<int>e,o;
        int even =0;
        int odd =0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(nums[i] %2 ==0 ){
                e.push_back(nums[i]);
            }
            if(nums[i] %2 !=0 ){
                o.push_back(nums[i]);
            }
        }
        for(int i=0;i<n;i++){
            if(i%2 == 0){
                nums[i] = e[even++];
            }
            else{
                nums[i] = o[odd++];
            }
        }
       return nums;
    }
};