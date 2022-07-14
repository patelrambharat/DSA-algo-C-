// Level order traversal 
// Easy Accuracy: 49.61% Submissions: 100k+ Points: 2
// Given a binary tree, find its level order traversal.
// Level order traversal of a tree is breadth-first traversal for the tree.


// Example 1:

// Input:
//     1
//   /   \ 
//  3     2
// Output:1 3 2
// Example 2:

// Input:
//         10
//      /      \
//     20       30
//   /   \
//  40   60
// Output:10 20 30 40 60

// Your Task:
// You don't have to take any input. Complete the function levelOrder() that takes the root node as input parameter and returns a list of integers containing the level order traversal of the given Binary Tree.


// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(N)
class Solution
{
    public:
    //Function to return the level order traversal of a tree.
    vector<int> levelOrder(Node* node)
    {
      //Your code here
      vector<int>ans;
      queue<Node*> q;
      q.push(node);
    //   q.push(NULL);
      while(!q.empty()){
          //tu nikal 
          Node* front = q.front();
          q.pop();
          
          ans.push_back(front -> data);
          //apne child ko chhod jaiyo
         if(front -> left != NULL){
             q.push(front -> left);
         }
         if(front -> right != NULL){
             q.push(front -> right);
         }
      }
      return ans;
    }
};