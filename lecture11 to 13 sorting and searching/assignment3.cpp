#include<bits/stdc++.h>
using namespace std;

int binarySearch(int arr[], int s, int e, int target) {
    int mid = s + (e-s)/2;

    while(s <= e) {
        if(arr[mid] == target)
            return mid;
        if(arr[mid] > target)
            e = mid - 1;
        else
            s = mid + 1;
        mid = s + (e-s)/2;    
    }
    return -1;
}

//we dont know the size of array, 
// considering it infinite as per question
//assumption array size if infinite, so no Index Out of Bound Exception
int findPosition(int arr[], int target) {
    int s = 0, e = 1;
    int val = arr[s];

    while(val < target) {
        s = e;
        e = 2*e;
        val = arr[e];
    }

    return binarySearch(arr, s, e, target);
}

bool binarysearch(vector<int>&arr,int s,int e,int target){
    int n = arr.size();
    s= 0;
    e = n-1;
    while(s<=e){
        int mid = (s+e)/2;
        if(arr[mid]==target){
            return true;
        }
        else if(arr[mid]>target){
            e = mid-1;
        }
        else {
            s = mid+1;
        }
    }
    return false;
}

int nanditsdouble(vector<int>& arr){
    int n = arr.size();
        sort(arr.begin(),arr.end());
        for(int i= 0;i<n;i++){
            if(arr[i] >= 0 and binarysearch(arr,i+1,n-1, 2*arr[i])){
                return true;
            }
            if(arr[i] < 0 && binarysearch(arr,i+1,n-1,arr[i]/2)){
                return true;
            }
        }
        return false;
}
int PeakInMountain(int arr[],int n){
    int start =0;
    int end =n-1;
    while(start<end){
        int mid = (start + end )/2;
        if(arr[mid] < arr[mid+1]){
            start = mid +1;
        }
        else{
            end = mid;
        }
        
        
    }
    return start;
}
int squareRoot(int n){
    int start = 0;
    int end = n-1;
    int res = -1;
    while(start<=end ){
        int mid = (start+end)/2;
        if(mid*mid == n){
            return mid;
        }
        else if(mid * mid < n){
            res = mid;
            start = mid+1;
        }
        else{
            end = mid-1;
        }
    }
    return res;
}

double morePrecision(int n ,int precision,int tempSol){
        double factor = 1;
        double ans = tempSol;
        for(int i=0;i<precision;i++){
                factor  = factor /10;
                for(double j = 0;j*j<n;j = j+factor){
                    ans =j;
                }
        }
        return ans;
}

int findPivot(int arr[],int n){

    int start =0;
    int end =n-1;
    while(start < end ){
        int mid = (start+end)/2;
        if(arr[mid] >= arr[0]){
            start = mid +1;
        }
        else{
            end = mid;
        }
    }
    return start;
}
int binarySearch(int arr[], int s, int e, int target) {
    int mid = s + (e-s)/2;

    while(s <= e) {
        if(arr[mid] == target)
            return mid;
        if(arr[mid] > target)
            e = mid - 1;
        else
            s = mid + 1;
        mid = s + (e-s)/2;    
    }
    return -1;
}
int SearchRotatedArray(int arr[],int n,int target){
        int pivot = findPivot(arr,n);
        if(target >= arr[pivot] && target <= arr[n-1]){
            return binarySearch(arr,pivot,n-1,target);
        }
        else {
            return binarySearch(arr,0,pivot-1,target);
        }
}
    int binarySearchfixed(int arr[],int n){
        int start=0;
        int end=n-1;
        while(start<=end){
            int mid = (start+end)/2;
            if(arr[mid] == mid){
                    return mid;
            }
            else if(arr[mid]<mid){
                    start = mid +1;
            }
            else{
                end = mid -1;
            }
        }
    }

   int count(int arr[], int n, int x) {
        int ft=0,lt=n-1;
        int f=-1,l=-1;
        int mid=-1;
        while(ft<=lt){
            mid=ft+(lt-ft)/2;
            if(arr[mid]==x){
                f=mid;
                lt=mid-1;
            } else if(x>arr[mid])
                ft=mid+1;
            else
                lt=mid-1;
        }
        if(f==-1)
            return 0;
        ft=0;
        lt=n-1;
        while(ft<=lt){
            mid=ft+(lt-ft)/2;
            if(arr[mid]==x){
                l=mid;
                ft=mid+1;
            } else if(x>arr[mid])
                ft=mid+1;
            else
                lt=mid-1;
        }
        return l-f+1;
    }

int first(int arr[],int n,int target){
    int start =0;
    int end =n-1;
    int ans =-1;
    while(start <= end){
        int mid = (start +end)/2;
        if(arr[mid]==target){
            ans =mid;
            end = mid - 1;
        }
        else if(arr[mid] > target){
            end = mid -1;
        }
        else {
            start= mid+1;
        }
    }
    return ans;
}
int last(int arr[],int n,int target){
    int start =0;
    int end =n-1;
    int ans = -1;
    while(start <= end){
        int mid = (start+end)/2;
        if(arr[mid] == target){
            ans = mid;
            start = mid +1;
        }
        else if(arr[mid] > target){
            end = mid -1;
        }
        else {
            start = mid +1;
        }
    }
    return ans;
}

int binarySearch(int arr[],int n,int target){
    //  int arr[] = { 2, 3, 4, 10, 40 }; input 
    int start =0;
    int end =n-1;
    while(start <= end){
        int mid = (start+end)/2;
        if(arr[mid]==target){
            return mid;
        }
        if(arr[mid]>target){
            end = mid-1;
        }
        else{
            start = mid+1;
            }
    }
    
}
int main(){
   
   int arr[] = {3, 5, 7, 9, 10, 90, 100, 130,
                               140, 160, 170};
    int ans = findPosition(arr, 10);
    if (ans==-1)
        cout << "Element not found";
    else
        cout << "Element found at index " << ans;
    return 0;
  
    return 0;

}