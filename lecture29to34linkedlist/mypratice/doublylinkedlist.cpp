#include<iostream>
using namespace std;
class Node{
    int data;
    Node* prev;
    Node* next;
    Node(int data){
        this -> data = data;
        
        this -> next = NULL;
    }
};
int main(){
    
    Node* temp = new Node(3);
    Node* head = temp;
    Node* tail = temp;
}