// Length of longest palindrome in linked list 
// Medium Accuracy: 49.91% Submissions: 10626 Points: 4
// Given a linked list, the task is to complete the function maxPalindrome() which returns an integer denoting  the length of the longest palindrome list that exist in the given linked list.

// Input:
// The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. The first line of each test case contains an integer N denoting the size of the linked list . Then in the next line are N space separated values of the given linked list.

// Output:
// For each test case output will be the required max length of the palindrome present in the given linked list.

// User Task:
// The task is to complete the function maxPalindrome() which should count the length of longest palindrome in the given list and return it.

// Constraints:
// 1 <= T <= 100
// 1 <= N <= 100

// Example:
// Input:
// 2
// 7
// 2 3 7 3 2 12 24
// 5
// 12 4 4 3 14

// Output:
// 5
// 2

// Explanation:
// Testcase 1: 2 -> 3 -> 7 -> 3 -> 2 is the linked list whose nodes leads to a palindrome as 2 3 7 3 2.

/*The function below returns an int denoting
the length of the longest palindrome list. */
int lenIfIsPalindrome(Node *h1,Node* h2){
    int len = 0;
    while(h1 && h2){
        if(h1->data==h2->data) len++;
        else break;
        
        h1 = h1->next;
        h2 = h2->next;
    }
    return len;
}//gives len of half list

int maxPalindrome(Node *head){
    int ans = 0;
    if(!head) return 0;
    if(!head->next) return 1;
    Node* curr = head,*nx = head->next,*prev = NULL;
    while(curr){
        nx = curr->next;
        curr->next = prev;
        
        ans = max(ans, 2*lenIfIsPalindrome(prev,nx)+1);
        ans = max(ans, 2*lenIfIsPalindrome(curr,nx));
        
        prev = curr;
        curr = nx;
    }
    return ans;
}