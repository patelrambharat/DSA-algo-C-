// Heap Sort
// MediumAccuracy: 49.91%Submissions: 61185Points: 4
// Lamp
// This problem is part of GFG SDE Sheet. Click here to view more.  

// Given an array of size N. The task is to sort the array elements by completing functions heapify() and buildHeap() which are used to implement Heap Sort.


// Example 1:

// Input:
// N = 5
// arr[] = {4,1,3,9,7}
// Output:
// 1 3 4 7 9
// Explanation:
// After sorting elements
// using heap sort, elements will be
// in order as 1,3,4,7,9.
// Example 2:

// Input:
// N = 10
// arr[] = {10,9,8,7,6,5,4,3,2,1}
// Output:
// 1 2 3 4 5 6 7 8 9 10
// Explanation:
// After sorting elements
// using heap sort, elements will be
// in order as 1, 2,3,4,5,6,7,8,9,10.

// Your Task :
// You don't have to read input or print anything. Your task is to complete the functions heapify(), buildheap() and heapSort() where heapSort() and buildheap() takes the array and it's size as input and heapify() takes the array, it's size and an index i as input. Complete and use these functions to sort the array using heap sort algorithm.
// Note: You don't have to return the sorted list. You need to sort the array "arr" in place.



class Solution
{
    public:
    //Heapify function to maintain heap property.
    void swap(int arr[], int i, int j){
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] =temp;
    }
    void heapify(int arr[], int n, int i)  
    {
      // Your Code Here
    
          int largest = i;
          int left = 2*i;
          int right = 2*i+1;
          if(left <n && arr[largest] < arr[left]){
              largest = left;
          }
          if(right < n && arr[largest] < arr[right]){
              largest = right;
          }
          if(largest != i){
              swap(arr, i, largest);
              heapify(arr,n, largest);
          
      }
    }

    public:
    //Function to build a Heap from array.
    void buildHeap(int arr[], int n)  
    { 
    // Your Code Here
    for(int i=n/2 ;i>=0;i--){
        heapify(arr, n,i);
    }
    }

    
    public:
    //Function to sort an array using Heap Sort.
    void heapSort(int arr[], int n)
    {
        //code here
        buildHeap(arr,n);
        for(int i=n-1;i>0;i--){
            swap(arr,0,i);
            heapify(arr,i,0);
        }
    }
};
