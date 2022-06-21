// Wave Array 
// Easy Accuracy: 62.9% Submissions: 100k+ Points: 2
// Given a sorted array arr[] of distinct integers. Sort the array into a wave-like array(In Place).
// In other words, arrange the elements into a sequence such that arr[1] >= arr[2] <= arr[3] >= arr[4] <= arr[5].....

// If there are multiple solutions, find the lexicographically smallest one.

// Example 1:

// Input:
// n = 5
// arr[] = {1,2,3,4,5}
// Output: 2 1 4 3 5
// Explanation: Array elements after 
// sorting it in wave form are 
// 2 1 4 3 5.
// Example 2:

// Input:
// n = 6
// arr[] = {2,4,7,8,9,10}
// Output: 4 2 8 7 10 9
// Explanation: Array elements after 
// sorting it in wave form are 
// 4 2 8 7 10 9.

//solution 1 sorting then swaping
//O(nlon)
 public:
    // arr: input array
    // n: size of array
    //Function to sort the array into a wave-like array.
    void convertToWave(int n, vector<int>& arr){
        
        // Your code here
        sort(arr.begin(),arr.end());
        for(int i=0;i<n-1;i+=2){
            swap(arr[i],arr[i+1]);
        }
    }
};

//approach 2
 public:
    // arr: input array
    // n: size of array
    //Function to sort the array into a wave-like array.
    void convertToWave(int n, vector<int>& arr){
        
        // Your code here
        for(int i=0;i<n;i+=2){
            if(i>0 && arr[i-1] > arr[i]){
                swap(arr[i],arr[i-1]);
            }
            if(i<n-1 && arr[i] < arr[i+1]){
                swap(arr[i],arr[i+1]);
            }
        }
        
    }
};