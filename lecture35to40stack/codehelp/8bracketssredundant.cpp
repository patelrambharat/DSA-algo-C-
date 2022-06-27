// Redundant Brackets
// Difficulty: EASY
// Contributed By
// Dhruv Sharma
// |
// Level 1
// Avg. time to solve
// 15 min
// Success Rate
// 85%
// Problem Statement
// Given valid mathematical expressions in the form of a string. You are supposed to return true if the given expression contains a pair of redundant brackets, else return false. The given string only contains ‘(‘, ’)’, ‘+’, ‘-’, ‘*’, ‘/’ and lowercase English letters.
// Note :
// A pair of brackets is said to be redundant when a subexpression is surrounded by needless/ useless brackets.
// For Example :
// ((a+b)) has a pair of redundant brackets. The pair of brackets on the first and last index is needless. 
// While (a + (b*c)) does not have any pair of redundant brackets. 
// Input Format :
// The first line contains a single integer ‘T’ denoting the number of test cases. The test cases follow.

// The first line of each test case contains a string denoting the expression.
// Output Format :
// For each test case, return “Yes” if the given expression contains at least one pair of redundant brackets, else return “No”.
// Note :
// You don’t need to print anything; It has already been taken care of. Just implement the given function.
// Constraints :

#include<stack>
bool findRedundantBrackets(string &s)
{
    // Write your code here.
    stack<char>st;
    for(int i=0;i<s.length();i++){
        char ch = s[i];
        if(ch == '(' || ch =='+' || ch == '-' || ch == '*' || ch == '/'){
            st.push(ch);
            
        }
        else{
            //ch ya  to closing bracket hai or lowercase letter
            if(ch == ')'){
                bool isredundant = true;
                while(st.top() != '('){
                    
                    char top = st.top();
                    if(top == '(' || top =='+' || top == '-' || top == '*' || top == '/'){
                        isredundant = false;
                    }
                    st.pop();
                }
                if(isredundant == true){
                    return true;
                }
                st.pop();
            }
        }
    }
    return false;
}
