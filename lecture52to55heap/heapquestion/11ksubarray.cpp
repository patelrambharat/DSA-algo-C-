class Solution{
public:
    int kthLargest(vector<int> &Arr,int N,int K){
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int i=0;i< N;i++){
            int store  = 0;
            for(int j=i;j<N;j++){
                
                store += Arr[j];
                if(pq.size() == K){
                    if(pq.top() < store){
                        pq.pop();
                        pq.push(store);
                    }
                }
                else
                    pq.push(store);
            }
        }
        return pq.top();
    }
};