// 526. Beautiful Arrangement
// Medium

// 2253

// 300

// Add to List

// Share
// Suppose you have n integers labeled 1 through n. A permutation of those n integers perm (1-indexed) is considered a beautiful arrangement if for every i (1 <= i <= n), either of the following is true:

// perm[i] is divisible by i.
// i is divisible by perm[i].
// Given an integer n, return the number of the beautiful arrangements that you can construct.

 

// Example 1:

// Input: n = 2
// Output: 2
// Explanation: 
// The first beautiful arrangement is [1,2]:
//     - perm[1] = 1 is divisible by i = 1
//     - perm[2] = 2 is divisible by i = 2
// The second beautiful arrangement is [2,1]:
//     - perm[1] = 2 is divisible by i = 1
//     - i = 2 is divisible by perm[2] = 1
// Example 2:

// Input: n = 1
// Output: 1

// Guess the reason is:

// Init, every number are in the right position: nums[i] == i; (index start from 1....)
// Then, if nums[i]%n==0 || n%nums[i]==0 is true, then i % n || nums[n] % i is also true, 
// both situation indicates safe to swap.
// And the swap keeps the property of that, so its no need to check the "(vs[n-1]%(i+1))==0 || (i+1)%vs[n-1])". 
// Just guess, hope someone can give a entire proof.
// I think if you change for loop condition to for (int i = n-1; i>=0; i--)
//  it makes me easier to understand cause it's 
// actually verifying if the number could be divided by index while doing the permutation


class Solution {
public:
    int count(int n,vector<int>&v){
        if(n<=0){
            return 1;
        }
        int cnt =0;
        for(int i=0;i<n;i++){
            if(v[i] % n ==0 || n % v[i] ==0){
                swap(v[i],v[n-1]);
                cnt += count(n-1,v);
                swap(v[i],v[n-1]);
            }
        }
        return cnt;
    }
    int countArrangement(int n) {
        vector<int>v;
        for(int i=1;i<=n;++i){
            v.push_back(i);
        }
        return count(n,v);
    }
};