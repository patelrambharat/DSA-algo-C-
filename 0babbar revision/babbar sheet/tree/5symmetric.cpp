class Solution {
public:
    bool symettric(TreeNode* a, TreeNode* b){
        if(a != NULL && b== NULL){
            return false;
        }
        if(a == NULL && b != NULL){
            return false;
        }
        if( a == NULL && b == NULL){
            return true;
        }
        if(a -> val != b-> val){
            return false;
        }
        return symettric(a-> left , b -> right) && symettric( a-> right, b-> left);
    }
    bool isSymmetric(TreeNode* root) {
       if(root == NULL){
            return true;
        }
        return symettric(root -> left , root -> right);
          
    }
};