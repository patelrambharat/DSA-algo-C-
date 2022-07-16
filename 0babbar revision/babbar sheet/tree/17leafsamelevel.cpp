// Leaf at same level 
// Easy Accuracy: 49.76% Submissions: 53193 Points: 2
// Given a Binary Tree, check if all leaves are at same level or not.

// Example 1:

// Input: 
//             1
//           /   \
//          2     3

// Output: 1

// Explanation: 
// Leaves 2 and 3 are at same level.

// Example 2:

// Input:
//             10
//           /    \
//         20      30
//        /  \        
//      10    15

// Output: 0

// Explanation:
// Leaves 10, 15 and 30 are not at same level.
class Solution{
  public:
    /*You are required to complete this method*/
    int height(Node* root){
        if(root == NULL){
            return 0;
        }
        return 1+ max(height(root -> left), height(root -> right));
    }
    bool check(Node *root)
    {
        //Your code here
        if(root == NULL){
            return true;
        }
        if(root -> left != NULL && root -> right != NULL){
            if(height(root -> left) != height(root -> right)){
                return false;
            }
        }
        return check(root -> left) && check(root -> right);
    }
};