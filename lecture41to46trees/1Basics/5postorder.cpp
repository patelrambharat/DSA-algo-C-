// 590. N-ary Tree Postorder Traversal
// Easy

// 1686

// 86

// Add to List

// Share
// Given the root of an n-ary tree, return the postorder traversal of its nodes' values.

// Nary-Tree input serialization is represented in their level order traversal. Each group of children is separated by the null value (See examples)

 

// Example 1:


// Input: root = [1,null,3,2,4,null,5,6]
// Output: [5,6,3,2,4,1]
// Example 2:


// Input: root = [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
// Output: [2,6,14,11,7,3,12,8,4,13,9,10,5,1]
 

// Constraints:

// The number of nodes in the tree is in the range [0, 104].
// 0 <= Node.val <= 104
// The height of the n-ary tree is less than or equal to 1000.
 

// Follow up: Recursive solution is trivial, could you do it iteratively?

// Accepted
// 189,702
// Submissions
// 247,973
// Seen this question in a real in
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int>postOrder(Node* root,vector<int> &postorder){
        if(root == NULL){
            return postorder;
        }
        for(int i=0;i<root -> children.size();i++){
            postOrder(root -> children[i],postorder);
        }
        postorder.push_back(root -> val);
        return postorder;
        
    }
    vector<int> postorder(Node* root) {
        vector<int> postorder;
        postOrder(root, postorder);
        return postorder;
    }
};