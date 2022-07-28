

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
