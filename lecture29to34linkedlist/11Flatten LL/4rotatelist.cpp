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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head -> next == NULL || k==0){
            return head;
        }
        //compute the length
        ListNode* curr = head;
        int len =1;
        while(curr -> next && ++len )
            curr = curr -> next;
            
        
        //go till that node
        curr  -> next = head;
        k= k % len;
        k = len - k;
        
        while(k--){
            curr = curr-> next;
        }
        //make the node head and break the connection
        head = curr -> next;
        curr -> next = NULL;
        return head;
    }
};