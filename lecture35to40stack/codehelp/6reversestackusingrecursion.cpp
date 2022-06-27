// Reverse a Stack 
// Medium Accuracy: 81.57% Submissions: 4228 Points: 4
// You are given a stack St. You have to reverse the stack using recursion.

 

// Example 1:

// Input:
// St = {3,2,1,7,6}
// Output:
// {6,7,1,2,3}
 

// Example 2:

// Input:
// St = {4,3,9,6}
// Output:
// {6,9,3,4}
 

// Your Task:

// You don't need to read input or print anything. Your task is to complete the function Reverse() which takes the stack St as input and returns the reversed stack.

 

// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(N)

class Solution{
public:
     void helper(vector<int> &ans,stack<int> &St)
   {
       if(St.size()==0)
       {
           return;
       }
       ans.push_back(St.top());
       St.pop();
       helper(ans,St);
   }
   vector<int> Reverse(stack<int> St){
       vector<int> ans;
       helper(ans,St);
       return ans;
       
   }
};
