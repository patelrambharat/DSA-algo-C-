// Two Stacks
// Difficulty: MEDIUM
// Contributed By
// Shivam Kumar Singh
// |
// Level 1
// Avg. time to solve
// 15 min
// Success Rate
// 85%
// Problem Statement
// Design a data structure, which represents two stacks using only one array common for both stacks. The data structure should support the following operations:
// push1(NUM) - Push ‘NUM’ into stack1.
// push2(NUM) - Push ‘NUM’ into stack2.
// pop1() - Pop out a top element from stack1 and return popped element, in case of underflow return -1.
// pop2() - Pop out a top element from stack2 and return popped element, in case of underflow return -1.
// There are 2 types of queries in the input
// Type 1 - These queries correspond to Push operation.
// Type 2 - These queries correspond to Pop operation.
// Note:
// 1. You are given the size of the array.

// 2. You need to perform push and pop operations in such a way that we are able to push elements in the stack until there is some empty space available in the array.

// 3. While performing Push operations, do nothing in the situation of the overflow of the stack.
// Input Format:
// The first line of the input contains two space-separated integers 'S' and 'Q', denoting the size of the array and number of operations to be performed respectively.

// The next 'Q' lines contain operations, one per line. Each line begins with two integers ‘type’ and ‘stackNo’, denoting the type of query as mentioned above and the stack number on which this operation is going to be performed.

// If the ‘type’ is 1 then it will be followed by one more integer ‘NUM’ denoting the element needed to be pushed to stack ‘stackNo’.
// Output Format:
// For each operation of Type 2, print an integer on a single line - popped element from the stack, if the stack is already empty print -1.
// Note:
// You do not need to print anything, it has already been taken care of. Just implement the given function.
// Constraints:
// 0 <= S <= 10^5
// 1 <= Q <= 5*10^5
// 1 <= type, stackNo <= 2
// 0 <= NUM <= 10^9

// Time Limit: 1 sec.   
class TwoStack {
	int *arr;
    int top1;
    int top2;
    int size;
public:

    // Initialize TwoStack.
    TwoStack(int s) {
        this -> size = s;
        top1 = -1;
        top2 = s;
        arr = new int[s];
    }
    
    // Push in stack 1.
    void push1(int num) {
        //atleast a empty space present
        if(top2 - top1 > 1 ) {
            top1++;
            arr[top1] = num;
        } 
       
    }

    // Push in stack 2.
    void push2(int num) {
         if(top2 - top1 > 1 ) {
            top2--;
            arr[top2] = num;
        } 
       
    }

    // Pop from stack 1 and return popped element.
    int pop1() {
		if( top1 >= 0) {
            int ans = arr[top1];
            top1--;
            return ans;
        }
        else
        {
            return -1;
        }
    }

    // Pop from stack 2 and return popped element.
    int pop2() {
		if( top2 < size) {
            int ans = arr[top2];
            top2++;
            return ans;
        }
        else
        {
            return -1;
        }
    }

};