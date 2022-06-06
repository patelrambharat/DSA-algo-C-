// 344. Reverse String
// Easy

// 5154

// 950

// Add to List

// Share
// Write a function that reverses a string. The input string is given as an array of characters s.

// You must do this by modifying the input array in-place with O(1) extra memory.

 

// Example 1:

// Input: s = ["h","e","l","l","o"]
// Output: ["o","l","l","e","h"]

class Solution {
public:
    
    void reverse(vector<char>& s,int i,int j){
        if(i>j){
            return;
        }
        swap(s[i],s[j]);
        i++;
        j--;
        //recursive call
        reverse(s,i,j);
    }
    void reverseString(vector<char>& s) {
       
        reverse(s,0,s.size()-1);
        
    }
};