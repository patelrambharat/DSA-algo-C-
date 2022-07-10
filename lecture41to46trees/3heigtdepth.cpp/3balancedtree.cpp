// 110. Balanced Binary Tree
// Easy

// 6380

// 340

// Add to List

// Share
// Given a binary tree, determine if it is height-balanced.

// For this problem, a height-balanced binary tree is defined as:

// a binary tree in which the left and right subtrees of every node differ in height by no more than 1.

 

// Example 1:


// Input: root = [3,9,20,null,null,15,7]
// Output: true
// Example 2:


// Input: root = [1,2,2,3,3,null,null,4,4]
// Output: false
// Example 3:

// Input: root = []
// Output: true
 


Approach-1 -> using Height of tree function || Time Complexity - O(n^2)

class Solution {
    private:
    int height(TreeNode* root){
        if(root==NULL) return 0;
        
        int left=height(root->left);
        int right=height(root->right);
        
        return max(left,right)+1;
		}
	public:
    bool isBalanced(TreeNode* root) {
        if(root==nullptr) return true;
        
        bool left=isBalanced(root->left);
        bool right=isBalanced(root->right);
        
        int diff = abs (height(root->left)-height(root->right)) ;
        
        if(left && right && diff<=1) return true;
        else
            return false;
	 }
};