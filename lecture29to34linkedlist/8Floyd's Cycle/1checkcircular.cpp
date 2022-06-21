// Check If Circular Linked List 
// Basic Accuracy: 50.74% Submissions: 83504 Points: 1
// Given head, the head of a singly linked list, find if the linked list is circular or not. A linked list is called circular if it not NULL terminated and all nodes are connected in the form of a cycle. An empty linked list is considered as circular.

// Note: The linked list does not contains any inner loop.

// Example 1:

// Input:
// LinkedList: 1->2->3->4->5
// (the first and last node is connected,
// i.e. 5 --> 1)
// Output: 1
// Example 2:

// Input:
// LinkedList: 2->4->6->7->5->1
// Output: 0
// Your Task:
// The task is to complete the function isCircular() which checks if the given linked list is circular or not. It should return true or false accordingly. (the driver code prints 1 if the returned values is true, otherwise 0)


bool isCircular(Node *head)
{
   // Your code here
   Node* slow = head;
   Node* fast = head;
   while(fast != NULL && fast -> next != NULL && fast -> next -> next != NULL){
       slow = slow -> next;
       fast = fast -> next -> next;
       
       if(slow == fast){
           return true;
       }
       
   }
   return false;
}
