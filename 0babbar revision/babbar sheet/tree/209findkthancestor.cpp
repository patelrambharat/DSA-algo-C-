Node* solveRec(Node* root , int &k , int node ) {
   
   if(root==NULL){
       return NULL;
   }
   
   if(root->data == node){
       return root;
   }
   
   Node* leftans = solveRec(root->left , k , node );
   Node* rightans =solveRec(root->right , k , node );
   
   
   if(leftans!=NULL && rightans==NULL){
       
       --k;
      
       if(k==0){
           return root;
       }
       
      return leftans;
   }


   else if(leftans==NULL && rightans!=NULL){
        
        --k;
       
       if(k==0){
           return root;
       }
           return rightans;   
   }
       
   else{
   return NULL;

   }


}

 

 

 


int kthAncestor(Node *root, int k, int node)
{
   // Code here
   
   Node* temp=solveRec(root , k , node );
   
   if(k>0){
       return -1;
   }
   
   return temp->data;
   
}
 