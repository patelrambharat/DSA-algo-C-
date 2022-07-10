Balanced or not:
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    pair<int, bool> solve(TreeNode* root) {
        if(root == NULL)
            return make_pair(0,true);
        
        pair<int,bool> leftAns = solve(root->left);
        pair<int,bool> rightAns = solve(root->right);
        
        int leftHeight = leftAns.first;
        int rightHeight = rightAns.first;
        
        bool diff = abs(leftHeight - rightHeight) <= 1;
        
        bool leftbalanced = leftAns.second;
        bool rightbalanced  = rightAns.second;
        
        if(leftbalanced && rightbalanced && diff) {
            return make_pair(max(leftHeight, rightHeight)+1, true);
        }
        else
        {
             return make_pair(max(leftHeight, rightHeight)+1, false);
        }
    }
    bool isBalanced(TreeNode* root) {
        pair<int,bool> ans = solve(root);
        return ans.second;
    }
};
Babbar — Yesterday at 10:05 PM
Symmetric Tree:
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool solve(TreeNode* a, TreeNode* b) {
        if( a == NULL && b == NULL)
            return true;
        if(a != NULL && b == NULL)
            return false;
        if(a == NULL && b != NULL)
            return false;
        if(a->val != b->val )
            return false;
        
        return solve(a->left, b->right) && solve(a->right, b->left);
    }
    bool isSymmetric(TreeNode* root) {
        if(root == NULL)
            return true;
        
        return solve(root->left, root->right);
    }
};
Babbar — Yesterday at 10:15 PM
Path Sum:
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == NULL)
            return false;
        
        if(root->val == targetSum && root->left == NULL && root->right == NULL)
            return true;
        
        bool leftAns = hasPathSum(root->left, targetSum - root->val);
        bool rightAns = hasPathSum(root->right, targetSum - root->val);
        
        return leftAns || rightAns;
    }
};
Babbar — Yesterday at 10:33 PM
LCA of Binary Tree: 
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL)
            return NULL;
        
        if(root == p || root == q)
            return root;
        else
        {
            TreeNode* leftAns = lowestCommonAncestor(root->left, p, q);
            TreeNode* rightAns = lowestCommonAncestor(root->right, p, q);
            
            if(leftAns != NULL && rightAns != NULL)
                return root;
            else if(leftAns == NULL)
                return rightAns;
            else
                return leftAns; 
        }
    }
};
Babbar — Yesterday at 10:56 PM
Path Sum III: 
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int count = 0 ;

    void solve(TreeNode* root, int target, long long int sum ) {
        if(root == NULL)
            return;
        
        if(target == sum)
            count++;
        
        if(root->left != NULL)
        solve(root->left, target, sum + root->left->val);
        
        if(root->right != NULL)
        solve(root->right, target, sum + root->right->val);
        
    }
    
    int pathSum(TreeNode* root, int targetSum) {
        if(root == NULL)
            return 0;
        
        //jis node pr khade ho,usko starting node maankar solve krne ka try karo
        solve(root, targetSum, root->val);
        
        pathSum(root->left, targetSum);
        pathSum(root->right, targetSum);
        return count;
    }
};
