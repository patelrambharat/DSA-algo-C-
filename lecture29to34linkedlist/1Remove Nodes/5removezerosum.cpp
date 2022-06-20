// 1171. Remove Zero Sum Consecutive Nodes from Linked List
// Medium

// 1465

// 75

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
    ListNode* removeZeroSumSublists(ListNode* head) {
    //steps
    //storing the prefix sum in a map
    //if same sum if foud again while traversing the list means the segment sum is 0
    //Thus we can delete the whole segment and make the curr node point to next of the node which made the sum 0
  
        //keep track of prefix sum
        unordered_map<int,ListNode*>m;
        
        ListNode* newhead=new ListNode(0);
        newhead->next=head;
        
        //initializing prefix sum
        m[0]=newhead;
        int currsum=0;
        while(head!=NULL)
        {
            //keep track of sum
            currsum+=head->val;
            
            //check in map if present
            if(m.find(currsum)!=m.end())
            {
                ListNode* prevoccurence=m[currsum];
                ListNode* starthead= prevoccurence;
                
                //storing current sum for deleting future nodes
                int sum=currsum;
                //go till head
                //example 3->4->2->-6->1
                //prefix sum 3->7->9->3->4
                //here head=-6 and prevoccurence=3
                //starthead = 3
                while(prevoccurence!=head)
                {
                    //delete 4->2->-6 sum=0
                    //delete from map 7->9
                    prevoccurence=prevoccurence->next;
                    sum+=prevoccurence->val;
                    if(prevoccurence!=head)
                    {
                        m.erase(sum);
                    }
                }
                //now prev is at -6
                starthead->next=head->next;  
            }
            else
            {
                m[currsum]=head;
            }
            
            head=head->next;
        }
        
        return newhead->next;
    }
};