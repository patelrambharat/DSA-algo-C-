// Sum of the Longest Bloodline of a Tree (Sum of nodes on the longest path from root to leaf node) 
// Easy Accuracy: 49.91% Submissions: 32062 Points: 2
// Given a binary tree of size N. Your task is to complete the function sumOfLongRootToLeafPath(), that find the sum of all nodes on the longest path from root to leaf node.
// If two or more paths compete for the longest path, then the path having maximum sum of nodes is being considered.

// Example 1:

// Input: 
//         4        
//        / \       
//       2   5      
//      / \ / \     
//     7  1 2  3    
//       /
//      6
// Output: 13
// Explanation:
//         4        
//        / \       
//       2   5      
//      / \ / \     
//     7  1 2  3 
//       /
//      6

// The highlighted nodes (4, 2, 1, 6) above are 
// part of the longest root to leaf path having
// sum = (4 + 2 + 1 + 6) = 13
// Example 2:

// Input: 
//           1
//         /   \
//        2     3
//       / \   / \
//      4   5 6   7
// Output: 11
// Your Task:
// You don't need to read input or print anything. Your task is to complete the function sumOfLongRootToLeafPath() which takes root node of the tree as input parameter and returns an integer denoting the sum of the longest root to leaf path of the tree. If the tree is empty, return 0.

class Solution
{
public:
    void solve(Node* root , int sum , int &maxsum ,int len , int &maxlen){
        //bace case
        if(root == NULL){
            if(len > maxlen){
                maxlen = len;
                maxsum = sum;
            }
            else if(len == maxlen){
                maxsum = max(sum , maxsum);
            }
            return;
        }
        sum = sum + root -> data;
        solve(root -> left, sum,maxsum , len+1, maxlen);
        solve(root -> right, sum , maxsum, len+1, maxlen);
    }
    int sumOfLongRootToLeafPath(Node *root)
    {
        //code here
        int len =0;
        int maxlen = 0;
        int sum =0;
        int maxsum  = INT_MIN;
        solve(root , sum , maxsum , len , maxlen);
        return maxsum;
    }
};