// 1593. Split a String Into the Max Number of Unique Substrings
// Medium

// 587

// 24

// Add to List

// Share
// Given a string s, return the maximum number of unique substrings that the given string can be split into.

// You can split string s into any list of non-empty substrings, where the concatenation of the substrings forms the original string. However, you must split the substrings such that all of them are unique.

// A substring is a contiguous sequence of characters within a string.

 

// Example 1:

// Input: s = "ababccc"
// Output: 5
// Explanation: One way to split maximally is ['a', 'b', 'ab', 'c', 'cc']. Splitting like ['a', 'b', 'a', 'b', 'c', 'cc'] is not valid as you have 'a' and 'b' multiple times.
// Example 2:

// Input: s = "aba"
// Output: 2
// Explanation: One way to split maximally is ['a', 'ba'].
// Example 3:

// Input: s = "aa"
// Output: 1
// Explanation: It is impossible to split the string any further.
class Solution {
public:
    void solve(int idx, string str, unordered_set<string> &s, int &cnt)
{
    if(cnt < s.size())
        cnt = s.size();
    
    string temp = "";
    for(int i=idx; i<str.length(); i++)
    {
        temp += str[i];
        if(s.find(temp) == s.end())
        {
            s.insert(temp);
            solve(i+1,str,s,cnt);
            s.erase(temp);
        }
    }
}

int maxUniqueSplit(string str) {
    
    unordered_set<string> s;
    int cnt = 0;
    
    solve(0,str,s,cnt);
    
    return cnt;
}
};