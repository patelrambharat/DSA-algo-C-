// Even and Odd 
// Easy Accuracy: 55.5% Submissions: 12762 Points: 2
// Given an array arr[] of size N containing equal number of odd and even numbers. Arrange the numbers in such a way that all the even numbers get the even index and odd numbers get the odd index.
// Note: There are multiple possible solutions, Print any one of them. Also, 0-based indexing is considered.

 

// Example 1:

// Input:
// N = 6
// arr[] = {3, 6, 12, 1, 5, 8}
// Output:
// 1
// Explanation:
// 6 3 12 1 8 5 is a possible solution.
// The output will always be 1 if your
// rearrangement is correct.
// Example 2:
// Input:
// N = 4
// arr[] = {1, 2, 3, 4}
// Output :
// 1

// Your Task:  
// You don't need to read input or print anything. Your task is to complete the function reArrange() which takes an integer N and an array arr of size N as input and reArranges the array in Place without any extra space.

class Solution {
  public:
    void reArrange(int arr[], int N) {
        // code here
         int even = 0,  odd = 1;
        while(even<N && odd<N){
            while(arr[even] % 2 == 0) even += 2;
            while(arr[odd] % 2 == 1) odd += 2;
            
            swap(arr[even], arr[odd]);
            
        }
    }
};
