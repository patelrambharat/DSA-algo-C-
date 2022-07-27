```
#include<iostream>
#include<queue>
using namespace std;

int getKthLargestElement(int arr[], int n, int k) {
    priority_queue<int, vector<int>, greater<int> > minHeap;

    //process first k element
    for(int i=0; i<k; i++) {
        minHeap.push(arr[i]);
    }


    //process remaining element
    for(int i=k; i<n; i++) {
        if(arr[i] > minHeap.top()) {
            minHeap.pop();
            minHeap.push(arr[i]);
        }
    }
    return minHeap.top();
}

int getMinCostRopes(int arr[], int n) {
    //initialise cost with 0
    int cost = 0;

    //create a min heap
    priority_queue<int, vector<int>, greater<int> > minHeap;

    //insert all array elements into min heap
    for(int i=0; i<n; i++) {
        minHeap.push(arr[i]);
    }

    while(minHeap.size() > 1) {
        //fetch 2 min elements and put their sum in cost 
        //and put element back in minHeap
        int first = minHeap.top();
        minHeap.pop();

        int second = minHeap.top();
        minHeap.pop();

        int sum = first + second;

        cost += sum;
        minHeap.push(sum);

    }
    return cost;
}

int main() {

    int arr[] = {4,3,2,6};
    int n = 4;
    cout << "Cost is " << getMinCostRopes(arr, n) << endl;

    // //max heap
    // priority_queue<int> q;

    // //insertion
    // q.push(1);
    // q.push(2);
    // q.push(5);
    // q.push(5);
    // q.push(3);

    // //top element or root element
    // cout << q.top() << endl;

    // //delete
    // q.pop();

    // cout << q.size() << endl;

    // if(q.empty())
    //     cout << "heap is empty " << endl;
    // else
    //     cout << "heap is not empty " << endl;


    // //min-heap
    // priority_queue<int, vector<int>, greater<int> > minHeap;

    // minHeap.push(5);
    // minHeap.push(4);
    // minHeap.push(3);
    // minHeap.push(1);
    // minHeap.push(2);

    // cout << minHeap.top() << endl;


    // int arr[] = {3,2,5,1,6,7,8,9};
    // int n = 8;
    // int k = 3;
    // cout << getKthLargestElement(arr, n, k) << endl;



    return 0;
}
```