// Merge Sort on Doubly Linked List 
// Medium Accuracy: 58.29% Submissions: 12314 Points: 4
// Given Pointer/Reference to the head of a doubly linked list of N nodes, the task is to Sort the given doubly linked list using Merge Sort in both non-decreasing and non-increasing order.

// Example 1:

// Input:
// N = 8
// value[] = {7,3,5,2,6,4,1,8}
// Output:
// 1 2 3 4 5 6 7 8
// 8 7 6 5 4 3 2 1
// Explanation: After sorting the given
// linked list in both ways, resultant
// matrix will be as given in the first
// two line of output, where first line
// is the output for non-decreasing
// order and next line is for non-
// increasing order.
// Example 2:

// Input:
// N = 5
// value[] = {9,15,0,-1,0}
// Output:
// -1 0 0 9 15
// 15 9 0 0 -1
// Explanation: After sorting the given
// linked list in both ways, the
// resultant list will be -1 0 0 9 15
// in non-decreasing order and 
// 15 9 0 0 -1 in non-increasing order.
// Your Task:
// The task is to complete the function sortDoubly() which sorts the doubly linked list. The printing is done automatically by the driver code.

// Constraints:
// 1 <= N <= 105


Node* merge(Node* head1, Node* head2) {
    Node* head = new Node(-1);
    Node* curr = head;
    while (head1 and head2) {
        if(head1->data <= head2->data) {
            curr->next = head1;
            head1->prev = curr;
            head1 = head1->next;
        } else {
            curr->next = head2;
            head2->prev = curr;
            head2 = head2->next;
        } 
        curr = curr->next;
    }
    if (head1) {
        curr->next = head1;
        head1->prev = curr;
    } else if (head2) {
        curr->next = head2;
        head2->prev = curr;
    }
    head = head->next;
    head->prev = NULL;
    return head;
}

struct Node *sortDoubly(struct Node *head)
{
	// Your code here
	if (!head or !head->next) return head;
	Node* slow = head;
	Node* fast = head;
	Node* prev = NULL;
	
	while (fast and fast->next) {
	    prev = slow;
	    slow = slow->next;
	    fast = fast->next->next;
	}
	prev->next = NULL;
	slow->prev = NULL;
	
	Node* head1 = sortDoubly(head);
	Node* head2 = sortDoubly(slow);
	return merge(head1, head2);
}