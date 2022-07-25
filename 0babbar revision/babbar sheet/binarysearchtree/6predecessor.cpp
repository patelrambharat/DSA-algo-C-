class Solution
{
public:
    Node* pre = NULL;
    void populateNext(Node *root)
    {
        //code here
        if(root == NULL){
            return;
        }
        
            populateNext(root -> left);
            if(pre != NULL){
                pre -> next = root;
            }
            pre = root;
            populateNext(root -> right);
        
    }
};