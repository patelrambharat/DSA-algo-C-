class Solution
{
   public:
    priority_queue<int> maxheap;
   priority_queue<int,vector<int>,greater<int>> minheap;
   double median=0;
   
   int signum(int a,int b)
   {
       if(a==b)
           return 0;
       else if(a>b)
           return 1;
       else
           return -1;
   }
   //Function to insert heap.
   void insertHeap(int &x)
   {
       switch(signum(maxheap.size(),minheap.size()))
       {
           case 0:if(x>median)
                   {
                       minheap.push(x);
                       median = (double)minheap.top();
                   }
                   else
                   {
                       maxheap.push(x);
                       median = (double)maxheap.top();
                   }
                   break;
           
           case 1:if(x>median)
                   {
                       minheap.push(x);
                       median = (double)(minheap.top()+maxheap.top())/2;
                   }
                   else
                   {
                       minheap.push(maxheap.top());
                       maxheap.pop();
                       maxheap.push(x);
                       median = (double)(minheap.top()+maxheap.top())/2;
                   }
                   break;
           
           case -1:if(x>median)
                   {
                       maxheap.push(minheap.top());
                       minheap.pop();
                       minheap.push(x);
                       median = (double)(minheap.top()+maxheap.top())/2;
                   }
                   else
                   {
                        maxheap.push(x);
                       median = (double)(minheap.top()+maxheap.top())/2;
                      
                   }
                   break;
                   
                   
       }
       
       
   }
   
   //Function to balance heaps.
   void balanceHeaps()
   {
       
   }
   
   //Function to return Median.
   double getMedian()
   {
      return median;
   }
};