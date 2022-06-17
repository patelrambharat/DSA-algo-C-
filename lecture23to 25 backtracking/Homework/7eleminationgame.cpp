// 390. Elimination Game
// Medium

// 789

// 515

// Add to List

// Share
// You have a list arr of all integers in the range [1, n] sorted in a strictly increasing order. Apply the following algorithm on arr:

// Starting from left to right, remove the first number and every other number afterward until you reach the end of the list.
// Repeat the previous step again, but this time from right to left, remove the rightmost number and every other number from the remaining numbers.
// Keep repeating the steps again, alternating left to right and right to left, until a single number remains.
// Given the integer n, return the last number that remains in arr.

 

// Example 1:

// Input: n = 9
// Output: 6
// Explanation:
// arr = [1, 2, 3, 4, 5, 6, 7, 8, 9]
// arr = [2, 4, 6, 8]
// arr = [2, 6]
// arr = [6]
// Example 2:

// Input: n = 1
// Output: 1


// For example , consider n= 10 , Input = 1,2,3,4,5,6,7,8,9,10
// let n = 2k , which is even
// After the first round of elimination from left to right, we are left with 2,4,6,8,10 (all odd nums are gone).
// (CASE 1)

// Now lets increment n, n becomes 11 , n= 11 ,input= 1,2,3,4,5,6,7,8,9,10,11.
// n = 2k+1 ,and n is odd.
// After the first round of elimination from left to right, we are left with 2,4,6,8,10 (all odd nums are gone).
// (CASE 2)

// we are left with the same set of elements in both cases.

// LtoR --> Elemination from left to right
// RtoL --> Elemination from right to left

// LtoR(2k elements) = LtoR(2k+1 elements) -----------------(1)

// When running intial eleminaton from left to right for 2k (n=10) elements , we are left with
// 2,4,6,,8,10 = 2*(1,2,3,4,5).

// This implies, running elimination from left to right for 2k elements is the same as 2 times running elimination from right to left for k elements.

// LtoR(2k elements) = 2*( RtoL(k elements))------------------ (2)

// Good, now we kind of reduced our bigger problem (2k elements) to a smaller problem (k elements).

// What if we run the elemination on same input , with different directions (LtoR and RtoL)
// for example,
// Input = 1,2,3,4,5
// When we do LtoR, 1st,3rd... element from LEFT are gone resulting in 2,4
// When we do RtoL, 1st,3rd... element from RIGHT are gone resulting in 4,2

// The relative position of elements in both the direction is same,

// So in LtoR, we found out that the kth element from left is the last remaining number, a similar pattern exists in RtoL, ie kth element from right to left will be the last remaining number.

// LtoR(k elements) -1 = k - RtoL(k elements)
// RtoL(k elements) = k -LtoR(k elements)+1 --------------------(3)

// sub, the value of RtoL(k elements) in (2)

// LtoR(2k elements) = 2*(k -LtoR(k elements)+1) .

// From our initial assumption n= 2k, we can replace 2k by n and k by n/2, the input

// LtoR(n) = 2*( (n/2)-LtoR(n/2) + 1)
// LtoR(1) = 1 , base case , will return 1 when n =1

int lastRemaining(int n) 
   
   {      
        if(n==1)
            return 1;
      return 2*((n/2)-lastRemaining(n/2)+1);        
    }
