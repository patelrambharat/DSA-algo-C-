// 148. Sort List
// Medium

// 7333

// 236

// Add to List

// Share
// Given the head of a linked list, return the list after sorting it in ascending order.

 

// Example 1:


// Input: head = [4,2,1,3]
// Output: [1,2,3,4]
// Example 2:


// Input: head = [-1,5,3,4,0]
// Output: [-1,0,3,4,5]
// Example 3:

// Input: head = []
// Output: []
 

// Constraints:

// The number of nodes in the list is in the range [0, 5 * 104].
// -105 <= Node.val <= 105


class Solution {
public:

  ListNode* getMid(ListNode* head) {
		ListNode* fast = head-> next;
		ListNode* slow = head;
		while(fast!=NULL && fast->next!=NULL)
		{
			fast=fast->next->next;
			slow=slow->next;
		}
		return slow;
	}
	
  ListNode* merge(ListNode* list1, ListNode* list2) {
		if( list1 == NULL)
			return list2;
		if(list2 == NULL)
			return list1;
		ListNode* ans = new ListNode;
		ListNode* temp = ans;
		while (list1 != NULL && list2 != NULL) {
			if (list1->val < list2->val) {
				temp->next = list1;
				temp = list1;
				list1 = list1->next;
			} else {
				temp->next = list2;
				temp = list2;
				list2 = list2->next;
			}
		}
	  while(list1 != NULL)
	  {
		  temp -> next = list1;
		  temp = list1;
		  list1 = list1 -> next;
	  }
	  while(list2 != NULL)
	  {
		  temp -> next = list2;
		  temp = list2;
		  list2 = list2 -> next;
	  }
	  ans = ans -> next;
	  return ans;
  }
   ListNode* sortList(ListNode* head)
  {
	  if(head==NULL || head->next == NULL)
	  {
		  return head;
	  }
	  
	  ListNode* mid = getMid(head);
	  ListNode* left = head;
	   ListNode* right = mid -> next;
	   mid->next = NULL;
	   
	  left = sortList(left);
	  right = sortList(right);
	  return merge(left, right);
  }
};