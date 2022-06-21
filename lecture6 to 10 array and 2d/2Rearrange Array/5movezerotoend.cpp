// 283. Move Zeroes
// Easy

// 9586

// 250

// Add to List

// Share
// Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

// Note that you must do this in-place without making a copy of the array.

 

// Example 1:

// Input: nums = [0,1,0,3,12]
// Output: [1,3,12,0,0]
// Example 2:

// Input: nums = [0]
// Output: [0]
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
         vector<int>pos,neg;
        int n= nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                neg.push_back(nums[i]);
            }
            else{
                pos.push_back(nums[i]);
            }
        }
        int i=0,j=0,k=0;
        while(i<pos.size()){
            nums[k++] = pos[i++];
        }
        while(j<neg.size()){
            nums[k++] = neg[j++];
        }
    }
};