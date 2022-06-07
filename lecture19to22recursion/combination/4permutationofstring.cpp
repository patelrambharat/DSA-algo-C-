// Permutations of a given string 
// Medium Accuracy: 49.85% Submissions: 47589 Points: 4
// Lamp
// This problem is part of GFG SDE Sheet. Click here to view more.   
// Given a string S. The task is to print all permutations of a given string in lexicographically sorted order.

 

// Example 1:

// Input: ABC
// Output:
// ABC ACB BAC BCA CAB CBA
// Explanation:
// Given string ABC has permutations in 6 
// forms as ABC, ACB, BAC, BCA, CAB and CBA .


class Solution{
	public:
	    void solve(string str,vector<string>&ans,int index){
	        if(index >= str.size()){
	            ans.push_back(str);
	            return;
	        }
	        //travese
	        for(int j = index;j<str.size();j++){
	            swap(str[index],str[j]);
	            solve(str,ans,index+1);
	            swap(str[index],str[j]);
	            
	        }
	    }
		vector<string>find_permutation(string S)
		{
		    // Code here there
		    vector<string>ans;
		    int index =0;
		    solve(S,ans,index);
		    return ans;
		}
};