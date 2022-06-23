// Clone a linked list with next and random pointer 
// Hard Accuracy: 49.62% Submissions: 41184 Points: 8
// You are given a special linked list with N nodes where each node has a next pointer pointing to its next node. You are also given M random pointers, where you will be given M number of pairs denoting two nodes a and b  i.e. a->arb = b.

// Construct a copy of the given list. The copy should consist of exactly N new nodes, where each new node has its value set to the value of its corresponding original node. Both the next and random pointer of the new nodes should point to new nodes in the copied list such that the pointers in the original list and copied list represent the same list state. None of the pointers in the new list should point to nodes in the original list.

// For example, if there are two nodes X and Y in the original list, where X.random --> Y, then for the corresponding two nodes x and y in the copied list, x.random --> y.

// Return the head of the copied linked list.

// ArbitLinked List1

// Example 1:

// Input:
// N = 4, M = 2
// value = {1,2,3,4}
// pairs = {{1,2},{2,4}}
// Output: 1
// Explanation: In this test case, there
// are 4 nodes in linked list.  Among these
// 4 nodes,  2 nodes have arbitrary pointer
// set, rest two nodes have arbitrary pointer
// as NULL. Second line tells us the value
// of four nodes. The third line gives the
// information about arbitrary pointers.
// The first node arbitrary pointer is set to
// node 2.  The second node arbitrary pointer
// is set to node 4.
// Example 2:

// Input:
// N = 4, M = 2
// value[] = {1,3,5,9}
// pairs[] = {{1,1},{3,4}}
// Output: 1
// Explanation: In the given testcase ,
// applying the method as stated in the
// above example, the output will be 1.

//Approach 1
 private:
    void insertAtTail(Node *head,Node *tail,int data){
        Node* newdata = new Node(data);
        if(head==NULL){
            head=newdata;
            tail=newdata;
            return;
        }
        else{
            tail->next=newdata;
            tail=newdata;
        }
       
    }
    public:
    Node *copyList(Node *head)
    {
        //clone the list
        Node* originalHead=head;
        Node* cloneHead=NULL;
        Node* cloneTail=NULL;
        while(originalHead!=NULL){
            insertAtTail(cloneHead,cloneTail,originalHead->data);
            originalHead=originalHead->next;
        }
        
        //create map
        
        unordered_map<Node* , Node*> myMap;
        originalHead=head;
        Node* temp = cloneHead;
        while(originalHead!=NULL){
            myMap[originalHead]=temp;
            originalHead=originalHead->next;
            temp=temp->next;
        }
        
        //random the ptr
        originalHead=head;
        temp = cloneHead;
        while(originalHead!=NULL){
            temp->arb= myMap[originalHead->arb];
            originalHead=originalHead->next;
            temp=temp->next;
        }
        return cloneHead;
    }




//Approach 2

TIME COMPLEXITY:0(N)

SPACE COMPLEXITY:0(1)

void insertAtTail(Node* &head,Node* &tail,int d){
        Node* temp=new Node(d);
        
        if(head==NULL){
            head=temp;
            tail=temp;
            return;
        }
        
        else{
            tail->next=temp;
            tail=temp;
        }
    }
    
    public:
    Node *copyList(Node *head)
    {
        // step-1 : make a clone ll
        
        Node* cloneHead=NULL;
        Node* cloneTail=NULL;
        
        Node* temp=head;
        
        while(temp!=NULL){
            insertAtTail(cloneHead,cloneTail,temp->data);
            temp=temp->next;
        }
        
        // step-2 : add clone nodes between original nodes
        
       Node* originalNode=head;
       Node* cloneNode=cloneHead;
       
       while(originalNode!=NULL && cloneNode!=NULL){
           
           Node* next=originalNode->next;
           originalNode->next=cloneNode;
           originalNode=next;
           
           next=cloneNode->next;
           cloneNode->next=originalNode;
           cloneNode=next;
           
       }
       
        
        // step-3 : random pointer copy
        
        temp=head;
        
        while(temp!=NULL){
            if(temp!=NULL){
                if(temp->arb!=NULL){
                    temp->next->arb=temp->arb->next;
                }
                
                else{
                    temp->next->arb=temp->arb;
                }
            }
            
            temp=temp->next->next;
        }
        
        // step-4 : revert the changes done in step-2
        
        originalNode=head;
        cloneNode=cloneHead;
        
        while(originalNode!=NULL && cloneNode!=NULL){
            
            originalNode->next=cloneNode->next;
            originalNode=originalNode->next;
            
            if(originalNode!=NULL){   // checked as original node move ahead two times first above and second time here
                cloneNode->next=originalNode->next;
                cloneNode=cloneNode->next;
            }
        }
        
        // step-5 : return ans;
        
        return cloneHead;
    }