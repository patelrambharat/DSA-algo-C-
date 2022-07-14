class Solution {
  public:
    // Function to return the diameter of a Binary Tree.
    int height(Node* root){
        if(root == NULL){
            return 0;
        }
        int leftAns = height(root -> left);
        int rightAns = height(root -> right);
        return 1+ max(leftAns , rightAns);
    }
    int diameter(Node* root) {
        // Your code here
        if(root == NULL){
            return 0;
        }
        int opt1 = diameter(root -> left);
        int opt2 = diameter(root -> right);
        int opt3 = 1 + height(root -> left) + height(root -> right);
        
        int ans = max(opt1, max(opt2,opt3));
        return ans;
    }
};