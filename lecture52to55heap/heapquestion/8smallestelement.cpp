class Solution{
    public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    int kthSmallest(int arr[], int l, int r, int k) {
        //code here
        int n = r-l+1;
       priority_queue<int>minheap;
        for(int i=0;i<k;i++){
            minheap.push(arr[i]);
        }
        for(int i=k;i<n;i++){
            if(arr[i] < minheap.top()){
                minheap.pop();
                minheap.push(arr[i]);
            }
        }
        return minheap.top();
        
    }
};