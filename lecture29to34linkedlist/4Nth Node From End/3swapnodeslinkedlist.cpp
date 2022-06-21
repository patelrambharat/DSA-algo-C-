// 1721. Swapping Nodes in a Linked List
// Medium

// 2849

// 107

// Add to List

// Share
// You are given the head of a linked list, and an integer k.

// Return the head of the linked list after swapping the values of the kth node from the beginning and the kth node from the end (the list is 1-indexed).

 

// Example 1:


// Input: head = [1,2,3,4,5], k = 2
// Output: [1,4,3,2,5]
// Example 2:

// Input: head = [7,9,6,6,7,8,3,0,9,5], k = 5
// Output: [7,9,6,6,8,7,3,0,9,5]
 

// Constraints:

// The number of nodes in the list is n.
// 1 <= k <= n <= 105
// 0 <= Node.val <= 100

// Solution
// The problem needs to be solved in the below steps:

// Step 1: Point to k-th node from the beginning.

// Point a pointer p1 to the head.
// Move the pointer forward in the linked list until we reached k-th node.
// Step 2: Point to k-th node from the end.

// Point 2 pointers slow and fast to the head.
// Move pointer fast till k-th node.
// Now move both the pointers fast & slow until fast has reached the last node.
// So when fast has reached the last node, slow must have been reached k-th node from the end.
// Step-3: Swap values of both the nodes.

// As we can guess that Point 2 of Step-2 can be done in the same loop of Point 1 of Step-1. This will save a bit of computation for us.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *p1 = head;
        for (int i = 1; i < k; i++)    //point to the begging of the list node
            p1 = p1->next;
        ListNode* slow = head, *fast =head;
        for( int i = 1; i <= k; ++i)   //point to the end of the list node
            fast = fast->next;

        while (fast) {
            fast = fast->next;       
            slow = slow->next;     //slow point to the kth node from end 
        }
        swap(slow->val, p1->val);
        return head;
    }
};