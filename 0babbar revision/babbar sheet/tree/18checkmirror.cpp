// Check Mirror in N-ary tree 
// Medium Accuracy: 53.24% Submissions: 15108 Points: 4
// Given two n-ary trees. Check if they are mirror images of each other or not. You are also given e denoting the number of edges in both trees, and two arrays, A[] and B[]. Each array has 2*e space separated values u,v denoting an edge from u to v for the both trees.


// Example 1:

// Input:
// n = 3, e = 2
// A[] = {1, 2, 1, 3}
// B[] = {1, 3, 1, 2}
// Output:
// 1
// Explanation:
//    1          1
//  / \        /  \
// 2   3      3    2 
// As we can clearly see, the second tree
// is mirror image of the first.
// Example 2:

// Input:
// n = 3, e = 2
// A[] = {1, 2, 1, 3}
// B[] = {1, 2, 1, 3}
// Output:
// 0
// Explanation:
//    1          1
//  / \        /  \
// 2   3      2    3 
// As we can clearly see, the second tree
// isn't mirror image of the first.


 1. Iterate over map of stack
      Push all connected nodes of each node of first tree in map of  stack.

  2. Again iterate over map for each node of second tree
      For example :     

      Let us take one node X of second tree 
      
      For this node X , check in map which stack is used

      a = Top of that stack for node X present in second tree;
      b = Connected node of X in second tree
      if (a != b)
           return false;
      pop node X from stack.

class Solution {
  public:
    int checkMirrorTree(int n, int e, int A[], int B[]) {
        // code here
        unordered_map<int,stack<int>>mp;
        for(int i=0;i<e*2;i = i+2){
            mp[A[i]].push(A[i+1]);
        }
        for(int i=0;i<2*e;i = i+2){
            if(mp[B[i]].top()!=B[i+1])
                return 0;
            mp[B[i]].pop();
        }
        return 1;
    }
};