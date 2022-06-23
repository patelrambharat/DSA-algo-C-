// Segregate even and odd nodes in a Link List 
// Easy Accuracy: 64.41% Submissions: 31622 Points: 2
// Given a link list of size N, modify the list such that all the even numbers appear before all the odd numbers in the modified list. The order of appearance of numbers within each segregation should be same as that in the original list.

// NOTE: Don't create a new linked list, instead rearrange the provided one.


// Example 1:

// Input: 
// N = 7
// Link List:
// 17 -> 15 -> 8 -> 9 -> 2 -> 4 -> 6 -> NULL

// Output: 8 2 4 6 17 15 9

// Explaination: 8,2,4,6 are the even numbers 
// so they appear first and 17,15,9 are odd 
// numbers that appear later.

public:
    Node* divide(int N, Node *head){
        // code here
        if(head == NULL || head -> next == NULL){
            return head;
        }
        Node* dummyeve = new Node(-1);
        Node* dummyodd = new Node(-1);
        Node* eventail = dummyeve;
        Node* oddtail = dummyodd; 
        Node* curr = head;
        while(curr != NULL){
            if(curr -> data %2 !=0){  //odd condition
                
                oddtail -> next = curr;
                oddtail = oddtail -> next;
            }
            else {
                eventail -> next = curr;
                eventail = eventail-> next;
            }
            curr = curr -> next;
        }
        eventail -> next = dummyodd -> next;
        oddtail -> next = NULL;
        return dummyeve -> next;
    }
};