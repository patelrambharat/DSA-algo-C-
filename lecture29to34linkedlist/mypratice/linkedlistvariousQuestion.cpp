#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this -> data = data;
        this -> next =NULL;
    }
};
void traverse(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp -> data<<" ";
        temp = temp -> next;
    }
    cout<<endl;
}
void insertAthead(Node* &head, int d){
    //step 1: create a new node
    Node * newNode= new Node(d);
    //step2: set next pointer to head
    newNode -> next = head;
    //step 2: update head
    head = newNode;
}
Node* reverse(Node* &head){
    if(head == NULL){
        cout<<"list is empty "<<endl;
        return head;
    }
    Node* curr = head;
    Node* prev = NULL;
    while(curr != NULL){
        //to keep track of list ahed
        Node* forward = curr -> next;
        curr -> next = prev;
        //aage badh jao
        prev = curr;
        curr = forward;

    }
    return prev;
}
Node* revrec(Node* curr, Node* prev){
    if(curr == NULL){
        return prev;
    }
    Node* forward = curr -> next;
    curr -> next = prev;
    return revrec(forward, curr);
}
Node* getmiddle(Node* head){
    if(head == NULL){
        cout<<"list is empty"<<endl;
        return NULL;
    }
    Node* slow = NULL;
    Node* fast = NULL;
    while(fast != NULL &&  fast -> next -> next != NULL){
        fast = fast -> next -> next;
        slow = slow -> next;
    }
    return slow;
}
bool iscircular(Node* &head){
    Node* temp = head;
    //to traverse the LL , in normal case 
    while(temp != NULL){
        //incase the list is circular 
        if(temp -> next == head){
                return true;
        }
        //move one node ahead 
        temp = temp -> next;
        //it means we have traversed the entries 
    }
    return false;
}
//very important question 
//reverse linked list in k group

Node* reverseInK(Node* &head , int k){
    //empty list 
    if(head == NULL){
        return NULL;
    }

    //steps 1.reverse first k nodes
    //step2.use recursion for remaining linked list
    //step3. connect linked list in step 1 with linked list in step2
    //step4 . return prev which is head of the entire list

    //step1
    Node* curr = head;
    Node* forward = curr -> next;
    Node* prev = NULL;
    int count  =0;
    while(curr != NULL && count <k){
        forward = curr -> next;
        prev = curr;
        curr = forward;
        count++;
    }

    //step2  pointer point for remaining linked list
    if(forward != NULL){
            Node* rem = reverseInK(forward , k);
            head -> next = rem;
    }
    //step 4 return head of the entire list
    return prev;
}
bool compare(Node* &temp1, Node* & temp2){
    while(temp1 != NULL && temp2 != NULL){
        if(temp1 -> data != temp2 -> data){
            
        }
    }
}
bool palindrome(Node* &head){
    //step1: break linkde list :: give :: midnode find 
    //step2:reverse 2nd half of the ::::Linked list
    //step3: compare both the  Linked list

    Node* mid = middleele(head);
    Node* temp1 = head;
    Node* temp2 = mid -> next;
    mid -> next = NULL;
    temp2 = reverse(temp2);

    return compare(temp1 , temp2);



}
int main(){
    Node* temp = new Node(3);
    Node * head= temp;
    Node* tail = temp;
    insertAthead(head, 5);
    insertAthead(head, 6);
    insertAthead(head, 7);
    insertAthead(head, 8);

    
   head = revrec(head,NULL);
   traverse(head);
   Node* middle = getmiddle(head);
   cout << "Middle is at " << middle->data << endl;

}