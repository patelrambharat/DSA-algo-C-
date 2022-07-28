// Merge two binary Max heaps
// EasyAccuracy: 59.55%Submissions: 13790Points: 2
// Given two binary max heaps as arrays, merge the given heaps to form a new max heap.

 

// Example 1:

// Input  : 
// n = 4 m = 3
// a[] = {10, 5, 6, 2}, 
// b[] = {12, 7, 9}
// Output : 
// {12, 10, 9, 2, 5, 7, 6}
// Explanation :
O(nlogn)



 

 

// Your Task:  
// You don't need to read input or print anything. Your task is to complete the function mergeHeaps() which takes the array a[], b[], its size n and m, as inputs and return the merged max heap. Since there can be multiple solutions, therefore, to check for the correctness of your solution, your answer will be checked by the driver code and will return 1 if it is correct, else it returns 0.

 

#include<queue>
class Solution{
public:	
	vector<int> kLargest(int arr[], int n, int k) {
	    // code here
	    vector<int>v;
	    priority_queue<int,vector<int>,greater<int>>minheap;
	    //process first k element 
	    for(int i=0;i<k;i++){
	        minheap.push(arr[i]);
	    }
	    for(int i=k;i<n;i++){
	        if(arr[i] > minheap.top()){
	            minheap.pop();
	            minheap.push(arr[i]);
	        }
	    }
	    while(minheap.empty() == false){
	        v.push_back(minheap.top());
	        minheap.pop();
	    }
	    reverse(v.begin(),v.end());
	    return v;
	}

};

O(n+m)

vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
       // your code here
       vector<int> c(n+m);
       int i=0,j=0,k=0;
       while(i<n && j<m && k<n+m){
           if(a[i]>b[j]){
               c[k]=a[i];
               k++;
               i++;
           }
           else{
               c[k]=b[j];
               k++;
               j++;
           }
       }
       while(i<n && k<n+m){
           c[k]=a[i];
           k++;
           i++;
       }
       while(j<m && k<n+m){
           c[k]=b[j];
           k++;
           j++;
       }
       return c;
   }