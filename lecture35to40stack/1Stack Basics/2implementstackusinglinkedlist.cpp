// Implement Stack using Linked List 
// Basic Accuracy: 49.96% Submissions: 69739 Points: 1
// Lamp
// This problem is part of GFG SDE Sheet. Click here to view more.   
// Let's give it a try! You have a linked list and you have to implement the functionalities push and pop of stack using this given linked list. Your task is to use the class as shown in the comments in the code editor and complete the functions push() and pop() to implement a stack. 

// Example 1:

// Input: 
// push(2)
// push(3)
// pop()
// push(4) 
// pop()
// Output: 3 4
// Explanation: 
// push(2)    the stack will be {2}
// push(3)    the stack will be {2 3}
// pop()      poped element will be 3,
//            the stack will be {2}
// push(4)    the stack will be {2 4}
// pop()      poped element will be 4
// Example 2:

// Input: 
// pop()
// push(4)
// push(5)
// pop()
// Output: -1 5
// Your Task: You are required to complete two methods push() and pop(). The push() method takes one argument, an integer 'x' to be pushed into the stack and pop() which returns an integer present at the top and popped out from the stack. If the stack is empty then return -1 from the pop() method.

// Expected Time Complexity: O(1) for both push() and pop().
// Expected Auxiliary Space: O(1) for both push() and pop().

// Constraints:
// 1 <= Q <= 100
// 1 <= x <= 100
#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node* next;

}
Node* top;
void push(int data){
    Node* temp = new Node();
    if(!temp){
        cout<<"\n stack overflow"<<endl;
        exit(1);
    }
    //add at the top and change top as new node
    temp -> data = data;
    temp -> next = top;
    top = temp;

}
int isEmpty(){
    //if top is null then empty
    return top== NULL;
}
int peek(){
    //if stack is not empty then return top node's data
    if(!isEmpty())
        return top -> data;
    else 
        exit(1);
}
void pop(){
    Node* temp;
    if(top == NULL){
        cout<<"\nStack Underflow"<<endl;
        exit(1);
    }
    else{
        temp =top;
        top = top -> next;
        free(temp);
    }

}



gfg solution 
//Function to push an integer into the stack.
void MyStack ::push(int x) 
{
     // Your Code
   StackNode* temp = new StackNode(x);
   temp->next = top;
   top = temp;

}

//Function to remove an item from top of the stack.
int MyStack ::pop() 
{
      // Your Code
   if(top == NULL) 
       return -1;
   
   int x = top->data;
   top = top->next;
   
   return x;

}