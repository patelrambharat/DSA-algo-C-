#include<queue>


class Info {
    public:
    int data;
    int row;
    int col;
    Info() {

    }
    Info(int d, int r, int c) {
        this->data = d;
        this->row = r;
        this->col = c;
    }
};

class Cmp {
    public:
    bool operator()(Info* a, Info* b) {
        return a->data > b->data;
    }
};

class Solution {
public:
    

vector<int> solve(vector<vector<int> > arr, int k, int n ) {
        
    int mini = INT_MAX;
    int maxi = INT_MIN;

    priority_queue<Info*, vector<Info*>, Cmp > minHeap; 
    //processs first k elements

    for(int i=0; i<k; i++) {
        int element = arr[i][0];
        mini = min(mini, element);
        maxi = max(maxi, element);
        minHeap.push(new Info(element, i, 0));
    }

    //for storing answer range
    int start = mini;
    int end = maxi;

    while(!minHeap.empty()) {

        //extract top element or minimum element and pop from heap
        Info* temp = minHeap.top();
        minHeap.pop();
        //save data in mini
        mini  = temp->data;


        //answer update
        if(end - start > maxi - mini ){
            end = maxi;
            start = mini;
        }

        //push next element, and update max
        if(temp->col + 1 < arr[temp->row].size()) {
            Info* toPush = new Info(arr[temp->row][temp->col + 1], temp->row, temp->col+1);
            minHeap.push(toPush);
            maxi = max(maxi, toPush->data);
        }
        else {
            break;
        }
    }
    vector<int> ans;
    ans.push_back(start);
    ans.push_back(end);
    return ans;
}

    vector<int> smallestRange(vector<vector<int>>& nums) {
        return solve(nums, nums.size(), 1);
    }
};
﻿