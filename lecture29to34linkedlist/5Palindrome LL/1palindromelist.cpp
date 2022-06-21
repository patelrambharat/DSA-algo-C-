// 234. Palindrome Linked List
// Easy

// 9295

// 572

// Add to List

// Share
// Given the head of a singly linked list, return true if it is a palindrome.

 

// Example 1:


// Input: head = [1,2,2,1]
// Output: true
// Example 2:


// Input: head = [1,2]
// Output: false
 

// Constraints:

// The number of nodes in the list is in the range [1, 105].
// 0 <= Node.val <= 9


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
    ListNode* midNode(ListNode* head){
        ListNode* slow = head, * fast = head;
        
        while( fast -> next != NULL && fast -> next -> next != NULL){
            fast = fast -> next -> next;
            slow = slow -> next;
        }
        
        return slow;
    }
    
    ListNode * reverse(ListNode * head){
        
        ListNode * prev = NULL;
        ListNode * curr = head, * temp;
        
        while(curr != NULL){
            temp = curr -> next;
            
            curr -> next = prev;
            prev = curr;
            curr = temp;
        }
        
        return prev;
    }
    
    bool compare(ListNode * l1, ListNode * l2){
        
        while(l1 != NULL && l2 != NULL){
            if(l1 -> val != l2 -> val){
                return false;
            }
            l1 = l1 -> next;
            l2 = l2 -> next;
        }
        
        return true;
    }
    bool isPalindrome(ListNode* head) {
        ListNode * mid = midNode(head);
        
        ListNode * l1 = head;
        
        ListNode * l2 = mid -> next;
        
        mid -> next = NULL;
        
        l2 = reverse(l2);
        
        return compare(l1, l2);
    }
};