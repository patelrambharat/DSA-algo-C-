// 241. Different Ways to Add Parentheses
// Medium

// 3713

// 185

// Add to List

// Share
// Given a string expression of numbers and operators, return all possible results from computing all the different possible ways to group numbers and operators. You may return the answer in any order.

 

// Example 1:

// Input: expression = "2-1-1"
// Output: [0,2]
// Explanation:
// ((2-1)-1) = 0 
// (2-(1-1)) = 2
// Example 2:

// Input: expression = "2*3-4*5"
// Output: [-34,-14,-10,-10,10]
// Explanation:
// (2*(3-(4*5))) = -34 
// ((2*3)-(4*5)) = -14 
// ((2*(3-4))*5) = -10 
// (2*((3-4)*5)) = -10 
// (((2*3)-4)*5) = 10

class Solution {
public:
    vector<int>rec(string& s,int start,int end){
        
        vector<int>ans;   //Declare ans vector for storing the ans
        for(int i=start;i<=end;i++){     // Traverse the string from start to end
            char ch = s[i];
            if(ch =='*' || ch == '+' || ch== '-'){
                // Get the answers for left and right part separated by the operator
           vector<int>leftval= rec(s,start,i-1);
           vector<int>rightval = rec(s,i+1,end);
            for(auto lval : leftval){     // For each number in leftVal, do the operation with each number in  //rightVal
                for(auto rval: rightval){
                    int temp;
                    if(ch == '*'){
                        temp = lval*rval;
                    }
                    else if(ch == '+'){
                        temp = lval + rval;
                    }
                    else if(ch=='-'){
                        temp = lval -rval;
                    }
                    ans.push_back(temp); // Push back the calculated temp value
                }
            }
            
        }
        }
         if(ans.empty())     // If ans is empty, it means that the string only contains a number and no  //operators
    // So just convert that number into an interger and push into the ans vector.
                ans.push_back(stoi(s.substr(start,end-start+1)));
        return ans;
    }
    vector<int> diffWaysToCompute(string expression) {
        vector<int>res;
        if(expression.empty())  // If the string is initially empty, return an empty vector
            return res;
        
        return rec(expression,0,expression.size()-1);
    }
};