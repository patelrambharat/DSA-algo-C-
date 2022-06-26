// 445. Add Two Numbers II
// Medium

// 3633

// 228

// Add to List

// Share
// You are given two non-empty linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

// You may assume the two numbers do not contain any leading zero, except the number 0 itself.

 

// Example 1:


// Input: l1 = [7,2,4,3], l2 = [5,6,4]
// Output: [7,8,0,7]
// Example 2:

// Input: l1 = [2,4,3], l2 = [5,6,4]
// Output: [8,0,7]
// Example 3:

// Input: l1 = [0], l2 = [0]
// Output: [0]
 

// Constraints:

// The number of nodes in each linked list is in the range [1, 100].
// 0 <= Node.val <= 9
// It is guaranteed that the list represents a number that does not have leading zeros.
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
        ListNode* curr = head;
        ListNode* pre = NULL;
        ListNode* ford = NULL;
        while(curr != NULL){
            ford = curr -> next;
            curr -> next = pre;
            pre = curr;
            curr = ford;
        }
        return pre;
    }
    void insertIntotail(ListNode* &head,ListNode* &tail,int data){
        ListNode* temp = new ListNode(data);
        
        //empty list
        if(head == NULL){
            head = temp;
            tail = temp;
            return;
        }
        else{
            tail -> next = temp;
            tail = temp;
        }
    }
    ListNode* add( ListNode* l1, ListNode* l2){
        ListNode* ansHead = NULL;
        ListNode* ansTail = NULL;
        int carry =0;
        while(l1 != NULL || l2 != NULL || carry !=0){
            int val1 = 0;
            if(l1 != NULL){
                val1 = l1 -> val;
            }
            int val2 = 0;
            if(l2 != NULL){
                val2 = l2 -> val;
            }
            int sum = carry +val1 + val2;
            int digit = sum % 10;
            
            insertIntotail(ansHead,ansTail,digit);
            carry = sum /10;
            if(l1 != NULL){
                l1 = l1 -> next;
            }
            
            if(l2 != NULL){
                l2 = l2 -> next;
            }
        }
        return ansHead;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverse(l1);
        l2 = reverse(l2);
        ListNode* ans = add(l1,l2);
        
        ans = reverse(ans);
        return ans;
    }
    
};  