class Solution
{
    public:
    int solve(Node* root , int &i , int k){
        if(root == NULL){
            return -1;
        }
        //left
        int right = solve(root -> right, i, k);
        if(right != -1){
            return right;
        }
        i++;
        if(i==k){
            return root -> data;
        }
        return solve(root -> left , i, k);
    }
    int kthLargest(Node *root, int K)
    {
        //Your code here
        int i=0;
        solve(root, i, K);
    }
};