class Solution{
 public:
   void inorder(Node* root,vector<int> &inord){
       //baase
       if(root==NULL){
           return;
       }
       
       inorder(root->left,inord);
       inord.push_back(root->data);
       inorder(root->right,inord);
   }
   void make_tree_in_postorder_format(Node* node,vector<int> &inord,int &i){
       if(i>inord.size() || node==NULL)
       return;
       
       //post order
       make_tree_in_postorder_format(node->left,inord,i);
       make_tree_in_postorder_format(node->right,inord,i);
       node->data=inord[i++];
   }
   void convertToMaxHeapUtil(Node* root)
   {
       // Your code goes here
       
       //appproach: 
       //step 1: create a new vector/array
       //step 2: calculate inorder of bst and push values in new vector
       //step 3: make a new tree from it with post orde traversal
       //result tree is a  max heap and fulfills second conditon also
       
       
       //in case if que is BST into min heap 
       //same process but in last make a tree with new vector in preorder manner
       
       //step1:
       vector<int> inord;
       inorder(root,inord);
       int i=0;
       make_tree_in_postorder_format(root,inord,i);
       
   }    
};