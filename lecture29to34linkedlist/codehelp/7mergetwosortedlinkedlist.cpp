// 21. Merge Two Sorted Lists
// Easy

// 12748

// 1161

// Add to List

// Share
// You are given the heads of two sorted linked lists list1 and list2.

// Merge the two lists in a one sorted list. The list should be made by splicing together the nodes of the first two lists.

// Return the head of the merged linked list.

 

// Example 1:


// Input: list1 = [1,2,4], list2 = [1,3,4]
// Output: [1,1,2,3,4,4]
// Example 2:

// Input: list1 = [], list2 = []
// Output: []
// Example 3:

// Input: list1 = [], list2 = [0]
// Output: [0]
 

// Constraints:

// The number of nodes in both lists is in the range [0, 50].
// -100 <= Node.val <= 100
// Both list1 and list2 are sorted in non-decreasing order.


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
    ListNode* mergeTwoLists(ListNode* head1, ListNode* head2) {
        
    
    if(head1 == NULL)
        return head2;

    if(head2 == NULL)
        return head1;
    
    ListNode* temp1 = head1;
    ListNode* temp2 = head2;

    ListNode* dummy = new ListNode(-1);
    ListNode* tempDummy = dummy;

    while(temp1 != NULL && temp2 != NULL) {

        if(temp1 -> val <= temp2 ->val) {
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

    
    ListNode* head = dummy->next;
    
    //delete dummy node
    dummy->next = NULL;
    delete dummy;

    return head;

    }
};