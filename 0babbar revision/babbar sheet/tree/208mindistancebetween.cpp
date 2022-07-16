class Solution{
    public:
    /* Should return minimum distance between a and b
    in a tree with given root*/
    Node* lca(Node* root , int a, int b){
        if(root == NULL){
            return NULL;
        }
        if(root -> data == a || root -> data ==b){
            return root;
        }
        Node* l = lca(root -> left, a, b);
        Node* r = lca(root -> right, a, b);
        if(l && r){
            return root;
        }
        if(l){
            return l;
        }
        else{
            return r;
        }
    }
    int solve(Node* root , int val){
        if(root == NULL){
            return NULL;
        }
        if(root -> data == val){
            return 1;
        }
        int l = solve(root ->left, val);
        int r = solve(root -> right, val);
        if(!l && !r){
            return 0;
        }
        else{
            return l+r+1;
        }
    }
    int findDist(Node* root, int a, int b) {
        // Your code here
        Node* LCA = lca(root , a, b);
        int x= solve(LCA, a);
        int y = solve(LCA,b);
        return x+y-2;
    }
};
