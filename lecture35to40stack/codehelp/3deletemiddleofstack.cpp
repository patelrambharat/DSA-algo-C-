// Delete middle element of a stack 
// Easy Accuracy: 50.06% Submissions: 46280 Points: 2
// Given a stack with push(), pop(), empty() operations, delete the middle of the stack without using any additional data structure.
// Middle: ceil((size_of_stack+1)/2) (1-based index)
 

// Example 1:

// Input: 
// Stack = {1, 2, 3, 4, 5}
// Output:
// ModifiedStack = {1, 2, 4, 5}
// Explanation:
// As the number of elements is 5 , 
// hence the middle element will be the 3rd
// element which is deleted
// Example 2:

// Input: 
// Stack = {1 2 3 4}
// Output:
// ModifiedStack = {1 3 4}
// Explanation:
// As the number of elements is 4 , 
// hence the middle element will be the 2nd
// element which is deleted
 

// Your Task:
// You don't need to read input or print anything. Complete the function deleteMid() which takes the stack and its size as input parameters and modifies the stack in-place.
// Note: The output shows the stack from top to bottom.


// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(N)


// Constraints:
// 2 ≤ size of stack ≤ 100

{
    public:
    void solve(stack<int>&s,int count, int size){
        if(count == size/2){   //middle tak pahuch gya
            s.pop();
            return;
        }
        int num = s.top();  //top ko side me rakh
        s.pop();   //hata diya
        //recursive call 
        solve(s,count+1,size);
        
        s.push(num);
    }
    //Function to delete middle element of a stack.
    void deleteMid(stack<int>&s, int sizeOfStack)
    {
        // code here..
        int count =0;
        solve(s,count,sizeOfStack);
    }
};
