class Solution{
  public:
    // The given root is the root of the Binary Tree
    // Return the root of the generated BST
    void inorder(Node* root , vector<int>&v){
        if(root == NULL){
            return;
        }
        inorder(root -> left, v);
        v.push_back(root -> data);
        inorder(root -> right,v);
    }
    Node* getBst(int s, int e, vector<int>&v){
        if(s>e){
            return NULL;
        }
        int mid = (s+e)/2;
        Node* root = new Node(v[mid]);
        root -> left = getBst(s, mid-1, v);
        root -> right = getBst(mid+1, e, v);
        return root;
    }
    Node *binaryTreeToBST (Node *root)
    {
        //Your code goes here
        vector<int>v;
        inorder(root , v);
        sort(v.begin(), v.end());
        return getBst(0,v.size()-1,v);
    }
};