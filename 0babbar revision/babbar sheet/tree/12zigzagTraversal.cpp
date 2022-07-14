// ZigZag Tree Traversal 
// Easy Accuracy: 49.78% Submissions: 73608 Points: 2
// Given a Binary Tree. Find the Zig-Zag Level Order Traversal of the Binary Tree.

 

// Example 1:

// Input:
//         3
//       /   \
//      2     1
// Output:
// 3 1 2
// Example 2:

// Input:
//            7
//         /     \
//        9       7
//      /  \     /   
//     8    8   6     
//    /  \
//   10   9 
// Output:
// 7 7 9 8 8 6 9 10 

class Solution{
    public:
    //Function to store the zig zag order traversal of tree in a list.
    vector <int> zigZagTraversal(Node* root)
    {
    vector<int> result;
    	if(root == NULL)
    	    return result;
    	
    	queue<Node*> q;
    	q.push(root);
    	
    	bool leftToRight = true;
    	
    	while(!q.empty()) {
    	    
    	    int size = q.size();
    	    vector<int> ans(size);
    	    
    	    //Level Process
    	    for(int i=0; i<size; i++) {
    	        
    	        Node* frontNode = q.front();
    	        q.pop();
    	        
    	        //normal insert or reverse insert 
    	        int index = leftToRight ? i : size - i - 1;
    	        ans[index] = frontNode -> data;
    	        
    	        if(frontNode->left)
    	            q.push(frontNode -> left);
    	            
    	        if(frontNode->right)
    	            q.push(frontNode -> right);
    	    }
    	    
    	    //direction change karni h
    	    leftToRight = !leftToRight;
    	   
    	  for(auto i: ans) {
    	      result.push_back(i);
    	  }  
    	}
    	    return result;
    }
};