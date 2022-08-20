#include<iostream>
#include<math.h>
#include<vector>
using namespace std;

//subset power set question


void solve(vector<int> nums,vector<int> output,int index,vector<vector<int> >&ans){
        //base case 
        if(index >= nums.size()){
            ans.push_back(output);
            return;
        }

        //exclude 
        solve(nums,output,index+1,ans);

        //include
        int element = nums[index];
        output.push_back(element);

        solve(nums,output,index+1,ans);
}

vector<vector<int>>subsets(vector<int>& nums){
    vector<vector<int>>ans;
    vector<int>output;
    int index=0;
    solve(nums,output,index,ans);
    return ans;

}

//binary search in an sorted array using recursion

int binarySearch(int arr[],int start,int end,int key){
  
   
     if(start>end)
        return -1;
    
      int mid = (start+end)/2;
        if(arr[mid]==key){
            return mid;

            }
        if(arr[mid]<key){
             binarySearch(arr,mid+1,end,key);
            }
        else{
             binarySearch(arr,0,mid-1,key);
            }          
    
}
//linear search in an array

bool linearSearch(int arr[],int n,int key){
        if(n==0){
            return false;
        }
        if(arr[0]==key){
            return true;
        }
        int remainingPart = linearSearch(arr+1,n-1,key);
        return remainingPart;
}
//get sum of the whole array using recursion

int SumoftheArray(int arr[],int n){
    if(n==0){
        return 0;

    }
    if(n==1){
        return n;
    }
    int remainingPart= SumoftheArray(arr+1,n-1);
    int sum = arr[0]+remainingPart;
    return sum;
}
//check is array is sorted or not using recursion

bool issorted(int arr[],int n){
    if(n==0 || n==1){
        return true;
    }
    if(arr[0]>arr[1]){
        return false;
    }
    return (issorted(arr+1,n-1));

}
int main(){
    int arr[7] ={2,4,6,9,11,13,19};
    int n=7;
    // cout<<issorted(arr,n);
    int key =19;

    cout<<binarySearch(arr,0,6,13);
}