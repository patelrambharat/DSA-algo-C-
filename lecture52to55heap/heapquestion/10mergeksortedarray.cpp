class node{
  public:
    int data, row, col;
    node(int data, int row, int col)
    {
        this->data = data;
        this->row = row;
        this->col = col;
    }
};

class compare{
  public:
    bool operator()(node* a, node* b)
    {
        return a->data > b->data;
    }
};

class Solution
{
    public:
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        priority_queue<node*, vector<node*>, compare> minHeap;
        
        //sab arrays ke first elements
        for(int i = 0; i < K; i++)
        {
            node* temp = new node(arr[i][0], i, 0);
            minHeap.push(temp);
        }
        
        vector<int> ans;
        
        while(minHeap.size() > 0)
        {
            node* topNode = minHeap.top();
            minHeap.pop();
            ans.push_back(topNode->data);
            
            int i = topNode->row, j = topNode->col;
            
            if(j+1 < arr[i].size())
            {
                node* pushedElement = new node(arr[i][j+1], i, j+1);
                minHeap.push(pushedElement);
            }
        }
        
        return ans;
    }
};