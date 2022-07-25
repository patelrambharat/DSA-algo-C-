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
    TreeNode* maxVal(TreeNode* root){
        TreeNode* temp = root;
        while(temp -> right != NULL){
            temp = temp -> right;    
        }
        return temp;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        
        
        if(root == NULL){
            return NULL;
        }
        //0 child
        if(root -> val == key){
        if(root -> left == NULL && root -> right == NULL){
            delete root;
            return NULL;
        }
        //1 child
        
        if(root -> left != NULL && root -> right == NULL){
            TreeNode* temp = root -> right;
            delete root;
            return temp;
            
        }
        if(root -> left == NULL && root -> right !=NULL){
            TreeNode* temp = root -> left;
            delete root;
            return temp;
        }
        
        //2 child
        if(root -> left != NULL && root -> right != NULL){
            //get inorderd pred
           int pred = maxVal(root -> left) -> val;
            //copy
            root -> val = pred;
            
            root -> left = deleteNode(root -> left, pred);
            
            return root;
        }
        }
        else if(key > root -> val){
            root -> right = deleteNode(root -> right , key );
            
        }
        else {
            root -> left = deleteNode(root -> left, key);
        }
        
        return root;
    }
};