// 61. Rotate List
// Medium

// 5482

// 1281

// Add to List

// Share
// Given the head of a linked list, rotate the list to the right by k places.

 

// Example 1:


// Input: head = [1,2,3,4,5], k = 2
// Output: [4,5,1,2,3]
// Example 2:


// Input: head = [0,1,2], k = 4
// Output: [2,0,1]
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
    
    int getLength(ListNode* head) {
        int len = 0;
        
        ListNode* temp = head;
        
        while(temp != NULL) {
            len++;
            temp = temp -> next;
        }
        return len;
    } 
    
    ListNode* rotateRight(ListNode* head, int k) {
        
        int n = getLength(head);
        
        
        if(head == NULL || head -> next == NULL || k == 0 || k % n == 0)
            return head;
        
        //update k
        k = k % n;
        
        ListNode* prev = NULL;
        ListNode* curr = head;
        
        int t = n-k;
        
        while(t--) {
            prev = curr;
            curr = curr->next;
        }
        
        //step2
        prev -> next = NULL;
        
            
        //step3: tail -> next = head
        ListNode* tail = curr;
        while(tail ->next != NULL) {
            tail = tail -> next;
        }
            
        tail -> next = head;
        
        //step4: return ans
        return curr;

        
    }
};