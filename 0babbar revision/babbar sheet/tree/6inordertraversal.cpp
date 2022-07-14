class Solution {
public:
    void InorderTr(TreeNode* root,vector<int>&inorder){
        if(root == NULL){
            return;
        }
        InorderTr(root -> left , inorder);
        inorder.push_back(root -> val);
        InorderTr(root -> right, inorder);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>inorder;
        
        InorderTr(root,inorder);
        return inorder;
    }
};