// 394. Decode String
// Medium

// 8334

// 362

// Add to List

// Share
// Given an encoded string, return its decoded string.

// The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer.

// You may assume that the input string is always valid; there are no extra white spaces, square brackets are well-formed, etc. Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. For example, there will not be input like 3a or 2[4].

// The test cases are generated so that the length of the output will never exceed 105.

 

// Example 1:

// Input: s = "3[a]2[bc]"
// Output: "aaabcbc"
// Example 2:

// Input: s = "3[a2[c]]"
// Output: "accaccacc"
// Example 3:

// Input: s = "2[abc]3[cd]ef"
// Output: "abcabccdcdcdef"

class Solution {
public:
    string helper(int &i,string s){
        int num=0;
        string word="";
        for(;i<s.length();i++)
        {
            if(s[i]>='0' and s[i]<='9')
                num=num*10+s[i]-'0';
            else if(s[i]=='[')
            {
                string ans=helper(++i,s);
                for(;num>0;num--)word+=ans;
            }
            else if(s[i]==']')
                return word;
            else
                word+=s[i];
        }
        return word;
    }
    string decodeString(string s) {
        int i=0;
        return helper(i,s);
    }
};