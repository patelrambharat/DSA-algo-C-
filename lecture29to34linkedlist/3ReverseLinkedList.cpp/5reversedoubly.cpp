// Reverse a Doubly Linked List 
// Easy Accuracy: 51.41% Submissions: 46968 Points: 2
// Given a doubly linked list of n elements. The task is to reverse the doubly linked list.

// Example 1:

// Input:
// LinkedList: 3 <--> 4 <--> 5
// Output: 5 4 3
// Example 2:

// Input:
// LinkedList: 75 <--> 122 <--> 59 <--> 196
// Output: 196 59 122 75
// Your Task:
// Your task is to complete the given function reverseDLL(), which takes head reference as argument and should reverse the elements so that the tail becomes the new head and all pointers are correctly pointed. You need to return the new head of the reversed list. The printing and verification is done by the driver code.

// Expected Time Complexity: O(n).
// Expected Auxiliary Space: O(1).

// Constraints:
// 1 <= number of nodes <= 103
// 0 <= value of nodes <= 103

Node* reverseDLL(Node * head)
{
    //Your code here
    if(head == NULL || head -> next == NULL){
        return head;
    }
    Node* prev = NULL;
    Node* curr = head;
    Node* ford = NULL;
    
    while(curr != NULL){
        ford = curr -> next;
        curr -> prev = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = ford;
    }
    return prev;
    
}