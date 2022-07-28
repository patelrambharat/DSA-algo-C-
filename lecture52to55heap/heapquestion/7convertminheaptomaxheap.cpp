void heapify(long *arr, int n, int i){
     int largest = i;
    int left = 2 * i+ 1;
    int right = 2*i+2;
    if(left < n && arr[largest] < arr[left]){
        largest = left;
    }
    if(right < n && arr[largest] < arr[right]){
        largest = right;
    }
    if(largest != i){
        swap(arr[i] , arr[largest]);
        heapify(arr, n, largest);
    }
}
void minHeapToMaxHeap(long *arr, int n)
{
    //Write your code here
    for(int i= n/2;i>=0;i--){
        heapify(arr, n,i);
    }
}