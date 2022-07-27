void inorder(Node* root , vector<int>& inorderVal){
    if(root == NULL){
        return;
        
    }
    inorder(root -> left, inorderVal);
    inorderVal.push_back(root -> data);
    inorder(root -> right, inorderVal);
    
}
Node* inordertobst(int s, int e, vector<int>& inorderVal){
    //base case 
    if(s> e){
        return NULL;
    }
    int mid = (s+e)/2;
    Node* root = new Node(inorderVal[mid]);
    root -> left = inordertobst(s , mid -1, inorderVal);
    root -> right = inordertobst(mid+1, e, inorderVal);
    return root;
}
Node* buildBalancedTree(Node* root)
{
	// Code here
	vector<int>inorderVal;
	
	//store 
	inorder(root , inorderVal);
	
	return inordertobst(0, inorderVal.size()-1, inorderVal);
}