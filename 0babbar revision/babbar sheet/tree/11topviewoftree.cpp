// Top View of Binary Tree 
// Medium Accuracy: 32.3% Submissions: 100k+ Points: 4
// Given below is a binary tree. The task is to print the top view of binary tree. Top view of a binary tree is the set of nodes visible when the tree is viewed from the top. For the given below tree

//        1
//     /     \
//    2       3
//   /  \    /   \
// 4    5  6   7

// Top view will be: 4 2 1 3 7
// Note: Return nodes from leftmost node to rightmost node.

// Example 1:

// Input:
//       1
//    /    \
//   2      3
// Output: 2 1 3
// Example 2:

// Input:
//        10
//     /      \
//   20        30
//  /   \    /    \
// 40   60  90    100
// Output: 40 20 10 30 100
// Your Task:
// Since this is a function problem. You don't have to take input. Just complete the function topView() that takes root node as parameter and returns a list of nodes visible from the top view from left to right.

// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(N).

// Constraints:
// 1 ≤ N ≤ 105
// 1 ≤ Node Data ≤ 105
 

// Note:The Input/Ouput format and Example given are used for system's internal purpose, and should be used by a user for Expected Output only. As it is a function problem, hence a user should not read any input from stdin/console. The task is to complete the function specified, and not to write the full code.

vector<int> topView(Node *root)
    {
        //Your code here
        vector<int>ans; //this is used to store ans
        if(root == NULL)
            return ans;
        
        map<int,int>topNode;  //this is used for one - one mapping 
        
        queue<pair<Node* , int>>q;
        q.push(make_pair(root,0));
        while(!q.empty()){
            
            pair<Node* , int> temp = q.front();
            //tu nikall
            q.pop();
            Node* frontNode = temp.first;
            int hd = temp.second;
            //if one value is present on horizontal distance then do not push other
            if(topNode.find(hd) == topNode.end())
                topNode[hd] = frontNode-> data;
            if(frontNode -> left)
                q.push(make_pair(frontNode -> left,hd -1));
            
            if(frontNode -> right )
                q.push(make_pair(frontNode -> right, hd+1));
        }
        for(auto i: topNode){
            ans.push_back(i.second);
        }
        
        return ans;
        
    }

};