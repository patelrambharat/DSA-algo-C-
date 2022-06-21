// Rotate Array 
// Basic Accuracy: 59.87% Submissions: 100k+ Points: 1
// Given an unsorted array arr[] of size N, rotate it by D elements (Anti - clockwise). 

// Input:
// The first line of the input contains T denoting the number of testcases. First line of each test case contains two space separated elements, N denoting the size of the array and an integer D denoting the number size of the rotation. Subsequent line will be the N space separated array elements.

// Output:
// For each testcase, in a new line, output the rotated array.

// Constraints:
// 1 <= T <= 200
// 1 <= N <= 107
// 1 <= D <= N
// 0 <= arr[i] <= 105

// Example:
// Input:
// 2
// 5 2
// 1 2 3 4 5 
// 10 3
// 2 4 6 8 10 12 14 16 18 20

// Output:
// 3 4 5 1 2
// 8 10 12 14 16 18 20 2 4 6

#include <iostream>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    int n,k;
	    cin>>n>>k;
	    int arr[n];
	    for(int i=0;i<n;i++){
	        cin>>arr[i];
	        
	    }
	    for(int i=0;i<n;i++){
	        cout<<arr[(i+k)%n]<<" ";
	        
	    }
	    cout<<"\n";
	}
	return 0;
}