// Print all possible paths from top left to bottom right of a mXn matrix

// Difficulty Level : Medium
// Last Updated : 08 Jun, 2022
// The problem is to print all the possible paths from top left to bottom right of a mXn matrix with the constraints that from each cell you can either move only to right or down.

// Examples : 

// Input : 1 2 3
//         4 5 6
// Output : 1 4 5 6
//          1 2 5 6
//          1 2 3 6

// Input : 1 2 
//         3 4
// Output : 1 2 4
//          1 3 4

// Program to Print All Possible Paths from Top Left to Bottom Right of a Matrix

#include<bits/stdc++.h>
using namespace std;

void printVector(vector<int> &v){

	for(auto it:v){
		cout<<it<<" ";
	}
	cout<<"\n";
}

void printPaths(int mat[][3], vector<int> v, int i, int j, int n, int m){
 
	if(i > n || j > m) return;         //base case when out of bond 

	v.push_back(mat[i][j]);            
	
	if(i==n && j==m){           //when reach to end print 
		printVector(v);
	}

	printPaths(mat,v,i+1,j,n,m);     //traversal left 
	printPaths(mat,v,i,j+1,n,m);   //traversal right

	v.pop_back();
}

void printPathUtil(int mat[][3], int n, int m){

	vector<int> v;
	printPaths(mat,v,0,0,n,m);
}

int main(){

	int mat[3][3]={
		{1,2,3},
		{4,5,6},
		{7,8,9}
	};

	int n=3,m=3;

	printPathUtil(mat,n-1,m-1);

	return 0;
}