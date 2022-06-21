// Given two sorted linked lists consisting of N and M nodes respectively. The task is to merge both of the list (in-place) and return head of the merged list.
 

// Example 1:

// Input:
// N = 4, M = 3 
// valueN[] = {5,10,15,40}
// valueM[] = {2,3,20}
// Output: 2 3 5 10 15 20 40
// Explanation: After merging the two linked
// lists, we have merged list as 2, 3, 5,
// 10, 15, 20, 40.
// Example 2:

// Input:
// N = 2, M = 2
// valueN[] = {1,1}
// valueM[] = {2,4}
// Output:1 1 2 4
// Explanation: After merging the given two
// linked list , we have 1, 1, 2, 4 as
// output.
// Your Task:
// The task is to complete the function sortedMerge() which takes references to the heads of two linked lists as the arguments and returns the head of merged linked list.

// Expected Time Complexity : O(n+m)
// Expected Auxilliary Space : O(1)
Node* merge(Node* &head1, Node* &head2) {
    
    if(head1 == NULL)
        return head2;

    if(head2 == NULL)
        return head1;
    
    Node* temp1 = head1;
    Node* temp2 = head2;

    Node* dummy = new Node(-1);
    Node* tempDummy = dummy;

    while(temp1 != NULL && temp2 != NULL) {

        if(temp1 -> data <= temp2 ->data) {
            tempDummy -> next = temp1;
            tempDummy = temp1;
            temp1 = temp1->next;
        }
        else{
            tempDummy -> next = temp2;
            tempDummy = temp2;
            temp2 = temp2->next;
        }
    }

    //it is possible that elements are left in temp1 list
    while(temp1 != NULL) {
         tempDummy -> next = temp1;
            tempDummy = temp1;
            temp1 = temp1->next;
    }

        //it is possible that elements are left in temp2 list
    while(temp2 != NULL) {
         tempDummy -> next = temp2;
            tempDummy = temp2;
            temp2 = temp2->next;
    }

    
    Node* head = dummy->next;
    
    //delete dummy node
    dummy->next = NULL;
    delete dummy;

    return head;
}