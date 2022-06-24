// Add 1 to a number represented as linked list 
// Easy Accuracy: 51.33% Submissions: 100k+ Points: 2
// A number N is represented in Linked List such that each digit corresponds to a node in linked list. You need to add 1 to it.

// Example 1:

// Input:
// LinkedList: 4->5->6
// Output: 457 
// Example 2:

// Input:
// LinkedList: 1->2->3
// Output: 124 
// Your Task:
// Your task is to complete the function addOne() which takes the head of the linked list as the only argument and returns the head of the modified linked list. The driver code prints the number.
// Note: The head represents the left-most digit of the number.

// Expected Time Complexity: O(N).
// Expected Auxiliary Space: O(1).
 public:
    Node* reverse(Node* head){
        Node* curr = head;
        Node* pre = NULL;
        Node* ford = NULL;
        while(curr != NULL){
            ford = curr -> next;
            curr -> next = pre;
            pre = curr;
            curr = ford;
            
        }
        return pre;
    }
    void insertintoTail(Node* &head,Node* &tail,int digit){
        Node* temp = new Node(digit);
        if(head == NULL){
            head = temp;
            tail = temp;
            return;
        }
        else{
            tail -> next = temp;
            tail = temp;
        }
    }
    
    Node* addOne(Node *head) 
    {
         /*
        1. reverse the linked list
        2. add 1 and propagate the carry forward
        3. reverse the linked list again
        */
        
        Node* newHead = reverse(head);
        Node* temp = newHead;
        
        while(temp){
            temp->data = (temp->data+1)%10;
            
            if(temp->data){
                break;
            }
            
            temp = temp->next;
        }
        
        if(not temp){
            temp = new Node(1);
            head->next = temp;
        }
        
        return reverse(newHead);
    }
};