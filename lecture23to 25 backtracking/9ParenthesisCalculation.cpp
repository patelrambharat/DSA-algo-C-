// 241. Different Ways to Add Parentheses
// Medium

// 3680

// 182

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
    vector<int> recurse(string s)
    {
        vector<int> ans;
        
        for(int k=0;k<s.length();k++)
        {
            if(s[k]=='+'||s[k]=='-'||s[k]=='*')
            {
                vector<int> v1,v2;
                v1=recurse(s.substr(0,k));
                v2=recurse(s.substr(k+1));
            
                for(int i2=0;i2<v1.size();i2++)
                {
                    for(int j2=0;j2<v2.size();j2++)
                    {
                        if(s[k]=='+')
                        {
                            ans.push_back(v1[i2]+v2[j2]);
                        }
                        if(s[k]=='-')
                        {
                            ans.push_back(v1[i2]-v2[j2]);
                        }
                        if(s[k]=='*')
                        {
                            ans.push_back(v1[i2]*v2[j2]);
                        }
                        //cout<<v1[i2]<<s[k]<<v2[j2]<<endl;
                    }
                }
            }
        }
        if(ans.size()==0)
        {
            ans.push_back(stoi(s));
        }
        return ans;
    }
    vector<int> diffWaysToCompute(string s){
      int n=s.length();
      return recurse(s);
    }
};