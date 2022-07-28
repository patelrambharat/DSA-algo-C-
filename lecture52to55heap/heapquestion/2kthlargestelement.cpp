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