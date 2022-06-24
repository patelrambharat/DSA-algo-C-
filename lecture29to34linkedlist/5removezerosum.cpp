// 1171. Remove Zero Sum Consecutive Nodes from Linked List
// Medium

// 1477

// 76

// Add to List

// Share
// Given the head of a linked list, we repeatedly delete consecutive sequences of nodes that sum to 0 until there are no such sequences.

// After doing so, return the head of the final linked list.  You may return any such answer.

 

// (Note that in the examples below, all sequences are serializations of ListNode objects.)

// Example 1:

// Input: head = [1,2,-3,3,1]
// Output: [3,1]
// Note: The answer [1,2,1] would also be accepted.
// Example 2:

// Input: head = [1,2,3,-3,4]
// Output: [1,2,4]
// Example 3:

// Input: head = [1,2,3,-3,-2]
// Output: [1]
 

// Constraints:

// The given linked list will contain between 1 and 1000 nodes.
// Each node in the linked list has -1000 <= node.val <= 1000.
// Accepted
// 37,023
// Submissions
// 86,775
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
    ListNode* solve( ListNode* &head, bool& anyChange) {
        if(head == NULL)
            return head;
        
         ListNode* temp = head;
        int sum = 0;
        
        while(temp != NULL) {
            sum = sum + temp->val;
            if(sum == 0)
                break;
            temp = temp -> next;
        }
        
        if(sum == 0) {
            anyChange = true;
            return temp -> next;
        }
        
        //agli node ko head mankar check karo, PS zero aaya ya nahi
        head -> next = solve(head -> next, anyChange);
        return head;
        
    }
    
    ListNode* removeZeroSumSublists(ListNode* head) {
        
        while(true) {
             bool anyChange = false;
             head = solve(head, anyChange);
            
             if(head == NULL || anyChange == false)
                 break;
        }
        return head;
    }
};
