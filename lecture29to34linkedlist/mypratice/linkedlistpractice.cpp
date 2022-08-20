#include<iostream>
using namespace std;
class Node{
    //data member are below 
public:
    int data;
    Node* next;
//constructor are pointed to below in this table 
Node(int data){
    this-> data = data;
    this -> next = NULL;
}
};
void insertAthead(Node* &head, int d){
    //step 1: create a new node
    Node * newNode= new Node(d);
    //step2: set next pointer to head
    newNode -> next = head;
    //step 2: update head
    head = newNode;
}
void insertAtTail(Node* &tail , int d){
    //step 1: create a new node
    Node* newNode = new Node(d);
    //step2: update tail ka next is newNode
    tail -> next = newNode;
    //step 3: tail update 
    tail = newNode;
}
void insertAtPosition(Node* &head, int pos, int d){
    //tail update , while inserting node at the end 
    //validate the position should be atmax 1 and current lenght of LL
    if(pos == 1){
        insertAthead(head, d);
    }
    //step 1 : creation of connection 
    //step 2: traverse of node n-1
    //step 3: connection update 
    Node * newNode = new Node(d);
    //step 2:
    Node* pre = head;
    int t = pos -2;   //because jb hm insert karenge to ek node ka space chahiye
    while(t--){
        pre = pre -> next;
    }
    //step 3:update connection
    newNode -> next = pre -> next;
    pre -> next = newNode;
}
void traverse(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp -> data<<" ";
        temp = temp -> next;
    }
    cout<<endl;
}

void deleteNode(Node* &head, int target, int pos){
    //empty list
    if(head == NULL){
        return;
    }
    Node* temp = head;
    Node* prev = NULL;
    if(target == temp -> data && pos == 1){
        head = head -> next;
        temp -> next = NULL;
        delete temp;

    }
    else{
        while(temp != NULL && temp -> data != NULL){
            prev = temp;
            temp = temp -> next;

        }
        //here we assuming we have already got that element
        if(temp == NULL){
            cout<<"Node not found"<<endl;
            return;
        }
        prev -> next = temp -> next;
        temp -> next =NULL;
        delete temp;
    }
}
int getlength(Node* &head){
    Node* temp = head;
    int len =0;
    while(temp != NULL){
            len++;
            temp = temp -> next;
    }
    return len;
}
int main(){
    Node* b = new Node(3);
    Node* head = b;
    Node* tail = b;
    insertAthead(head, 9);
    insertAtPosition(head, 3, 10);
    insertAtTail(tail,5);
    insertAtTail(tail,6);
    insertAtTail(tail,7);
    insertAtTail(tail,8);
    deleteNode(head, 9, 1);
    traverse(head);
    cout<<getlength(head);
    return 0;
}