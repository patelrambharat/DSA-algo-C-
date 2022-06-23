// 143. Reorder List
// Medium

// 6242

// 222

// Add to List

// Share
// You are given the head of a singly linked-list. The list can be represented as:

// L0 → L1 → … → Ln - 1 → Ln
// Reorder the list to be on the following form:

// L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
// You may not modify the values in the list's nodes. Only nodes themselves may be changed.

 

// Example 1:


// Input: head = [1,2,3,4]
// Output: [1,4,2,3]
// Example 2:


// Input: head = [1,2,3,4,5]
// Output: [1,5,2,4,3]

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
    ListNode* reverse(ListNode* head){   
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = NULL;
        while(curr != NULL){
            next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        ListNode* fast = head;         //find middle of the linked list
        ListNode* slow = head;
        while(fast != NULL && fast -> next != NULL){
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        
        //breaking the linked list
        ListNode* firsthalf = head;
        ListNode* secondhalf = slow -> next;   //mid ka next is second half head
        slow -> next = NULL;
        secondhalf = reverse(secondhalf);
        
        while(firsthalf != NULL && secondhalf != NULL)   //join them 
        {
            ListNode* x = firsthalf -> next;
            ListNode* y = secondhalf -> next;
            firsthalf -> next = secondhalf;
            secondhalf -> next = x;
            secondhalf = y;
            firsthalf = x;
        }
        
        
        
    }
};