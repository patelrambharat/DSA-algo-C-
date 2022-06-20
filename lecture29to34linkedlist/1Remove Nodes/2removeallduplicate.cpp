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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head -> next == NULL){
            return head;
        }
        ListNode* dummy = new ListNode(-1);
        ListNode* itr = dummy;
        itr -> next = head;   //potential unique element 
        ListNode* curr = head -> next;
        
        while(curr != NULL){
            bool isLooprun = false;
            while(curr != NULL && itr -> next -> val == curr -> val){
                isLooprun = true;
                curr = curr -> next;
            }
            if(isLooprun)
                itr -> next = curr;
            else 
                itr = itr -> next;
            if(curr != NULL )
                curr = curr -> next;
        }
       return dummy -> next;
        
    }
};