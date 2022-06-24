// Problem Statement
// Given two numbers represented by linked lists. Your task is to find the multiplied list and return the head of the multiplied list.
// The multiplied list is a linked list representation of the multiplication of two numbers.
// Input Format:
// The first line of input contains a single integer T, representing the number of test cases or queries to be run. 

// Then the T test cases follow.

// The first line of each test case contains the elements of the first singly linked list separated by a single space and terminated by -1. Hence, -1 would never be a list element.

// The second line of each test case contains the elements of the second singly linked list separated by a single space and terminated by -1. Hence, -1 would never be a list element.
// Output Format:
// For each test case, print the multiplied linked list. The elements of the multiplied list should be single-space separated, terminated by -1.

// The output of each test case is printed in a separate line.
// Note :
// You do not need to print anything, it has already been taken care of. Just implement the given function.
// Constraints :
// 1 <= T <= 10
// 1 <= N, M <= 100
// 0 <= data <= 9

// Where N and M are the number of nodes in the two linked lists.

// Time Limit: 1 sec
// Sample Input 1:
// 1
// 5 6 3 -1
// 8 4 2 -1
// Sample Output 1:
// 4 7 4 0 4 6 -1
// Explanation Of Sample Input 1:
// 563 * 842 = 474046
// Sample Input 2:
// 2
// 7 5 9 4 6 -1
// 0 -1
// 0 2 3 4 0 - 1
// 0 0 1 -1

Node *reverse(Node *head){
	if(!head || !head->next)
		return head;
	
	Node *cur=head,*prev=NULL;
	while(cur){
		Node *nxt=cur->next;
		cur->next=prev;
		prev=cur;
		cur=nxt;
	}
	return prev;
}
Node *newList(Node *l1,Node *l2){
	Node *head=new Node(-1);
	Node *last=head;
	int n=10000;
	while(l1){
		last->next=new Node(0);
		last=last->next;
		l1=l1->next;
	}
	while(l2){
		last->next=new Node(0);
		last=last->next;
		l2=l2->next;
	}
	
	return head->next;
}
Node *removeEmpty(Node *head){
	Node *newhead;
	bool flag=false;
	while(head){
		if(head->data!=0){
			newhead=head;
			flag=true;
			break;
		}
		head=head->next;
	}
	
	return flag==true?newhead:new Node(0);
}
Node *multiplyLL(Node *head1, Node *head2){
    // Write your code here
	head1=reverse(head1);
	head2=reverse(head2);
	Node *second=head2;
	Node *ansList=newList(head1,head2);
	Node *start=ansList;
	
	while(second){
		int data =second->data;
		int carry=0;
		Node *first=head1;
		Node *ansNode=start;
		while(first){
			int val=data*first->data+carry+ansNode->data;
			ansNode->data=val%10;
			carry=val/10;
			ansNode=ansNode->next;
			first=first->next;
		}
		while(carry>0){
			ansNode->data=(ansNode->data+carry)%10;
			ansNode=ansNode->next;
			carry/=10;
		}
		start=start->next;
		second=second->next;
	}
	ansList=reverse(ansList);
return	removeEmpty(ansList);	
}