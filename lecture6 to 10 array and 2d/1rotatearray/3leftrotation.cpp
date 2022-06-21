Rotate Array 
Easy Accuracy: 50.28% Submissions: 100k+ Points: 2
Given an unsorted array arr[] of size N. Rotate the array to the left (counter-clockwise direction) by D steps, where D is a positive integer. 

 

Example 1:

Input:
N = 5, D = 2
arr[] = {1,2,3,4,5}
Output: 3 4 5 1 2
Explanation: 1 2 3 4 5  when rotated
by 2 elements, it becomes 3 4 5 1 2.
Example 2:

Input:
N = 10, D = 3
arr[] = {2,4,6,8,10,12,14,16,18,20}
Output: 8 10 12 14 16 18 20 2 4 6
Explanation: 2 4 6 8 10 12 14 16 18 20 
when rotated by 3 elements, it becomes 
8 10 12 14 16 18 20 2 4 6.


#Approach


Input arr[] = [1, 2, 3, 4, 5, 6, 7], d = 2, n =7
1) Store the first d elements in a temp array
   temp[] = [1, 2]
2) Shift rest of the arr[]
   arr[] = [3, 4, 5, 6, 7, 6, 7]
3) Store back the d elements
   arr[] = [3, 4, 5, 6, 7, 1, 2]
  public:
    
    //Function to rotate an array by d elements in counter-clockwise direction. 
    void rotateArr(int arr[], int d, int n){
        // code here
        int temp[n];
        if(d>n){
            d = d-n;
        }
        for(int i=0;i<n;i++){
            temp[((i+n)-d)%n] = arr[i];
        }
        for(int i=0;i<n;i++){
            arr[i] = temp[i];
        }
      
    }
};