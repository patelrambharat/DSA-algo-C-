// Segregate Even and Odd numbers 
// Basic Accuracy: 53.38% Submissions: 6241 Points: 1
// Given an array Arr[], write a program that segregates even and odd numbers. The program should put all even numbers first in sorted order, and then odd numbers in sorted order.

// Example 1:

// Input: 
// N = 7
// Arr[] = {12, 34, 45, 9, 8, 90, 3}
// Output: 8 12 34 90 3 9 45
// Explanation: Even numbers are 12, 34,
// 8 and 90. Rest are odd numbers. After
// sorting even numbers 8 12 34 90 and 
// after sorting odd numbers 3 9 45. Then
// concat both.
// Example 2:

// Input: 
// N = 5
// Arr[] = {0, 1, 2, 3, 4}
// Output: 0 2 4 1 3
// Explanation: 0 2 4 are even and 1 3
// are odd numbers.
class Solution{
public:	

	void segregateEvenOdd(int arr[], int n) {
	    // code here
	    vector<int>ans;
	    sort(arr,arr+n);
	    for(int i=0;i<n;i++){
	        if(arr[i]%2 == 0){
	            ans.push_back(arr[i]);
	        }
	       
	    }
	    for(int i=0;i<n;i++){
	        if(arr[i] %2 !=0){
	            ans.push_back(arr[i]);
	        }
	    }
	    int k=0;
	    for(int i=0;i<ans.size();i++){
	        arr[k++] = ans[i];
	    }
	}
};