class Solution
{
    public:
    //Function to return the lowest common ancestor in a Binary Tree.
    Node* lca(Node* root ,int n1 ,int n2 )
    {
       //Your code here 
       if(root == NULL){
           return NULL;
       }
       if(root -> data ==  n1 || root -> data == n2){
           return root;
       }
       else{
           Node* leftans = lca(root -> left , n1,n2);
           Node* rightans = lca(root -> right , n1, n2);
           if(leftans != NULL && rightans != NULL){
               return root;
           }
           else if(leftans == NULL){
               return rightans;
           }
           else{
               return leftans;
           }
       }
    }
};