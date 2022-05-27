#include<bits/stdc++.h>
using namespace std;

 int maxSubArray(vector<int>& nums) {

    // input nums = [-2,1,-3,4,-1,2,1,-5,4]
    // Output: 6
        int sum =0;
        int ans = INT_MIN;
        for(int i=0;i<nums.size();i++){
            sum = sum + nums[i];
            ans = max(ans ,sum);
            if(sum <0){
                sum = 0;}
        }
        return ans;
    }

bool uniqueOccurrences(vector<int> &arr) {

    unordered_map<int,int> m;
    
    // counting the frequency of elements
    for(int i=0;i<arr.size();i++){
        m[arr[i]]++;
    }
    vector<int>ans;
    // copy frequency of map into vector
    for(auto i:m) ans.push_back(i.second);
    
    // copy vector into set
    set<int>st(ans.begin(),ans.end());
    
    int n=ans.size();
    int y=st.size();
    
    //compare vector size and set size
    if(n==y) return true;
    return false;
}



int minSwap(int arr[],int n,int k){

    //  this is input int arr[] = {2, 1, 5, 6, 3};
    // int n = sizeof(arr) / sizeof(arr[0]);
    // int k = 3;
    // cout << minSwap(arr, n, k) << "\n";
     
    // int arr1[] = {2, 7, 9, 5, 8, 7, 4};
    // n = sizeof(arr1) / sizeof(arr1[0]);
    // k = 5;
    // cout << minSwap(arr1, n, k);



        int cnt =0;
        for(int i=0;i<n;i++){
            if(arr[i]<=k){
                cnt++;
            }
        }
        int bad =0;
        for(int i=0;i<cnt;i++){
            if(arr[i] > k){
                bad++;
            }
        }
        int ans = bad;
        for(int i=0 , j=cnt;j<n;i++,j++){
            if(arr[i]>k){   // Decrement count of previous window
                bad--;
            }
            if(arr[j]>k){
                bad++; // Increment count of current window
            }
            ans = min(ans ,bad);
        }
        return ans;
}
//efficient solution
bool checkPalindrome(int arr[],int n){
    int s=0;
    int e = n-1;
    while(s<=e){
        if(arr[s] == arr[e]){
            return true;
            s++;
            e--;
        }
        else {
            return false;
        }
    }
}
bool find3Numbers(int A[], int arr_size, int sum)
{
    // Fix the first element as A[i]
    for (int i = 0; i < arr_size - 2; i++)
    {
 
        // Find pair in subarray A[i+1..n-1]
        // with sum equal to sum - A[i]
        unordered_set<int> s;
        int curr_sum = sum - A[i];
        for (int j = i + 1; j < arr_size; j++)
        {
            if (s.find(curr_sum - A[j]) != s.end())
            {
                printf("Triplet is %d, %d, %d", A[i],
                       A[j], curr_sum - A[j]);
                return true;
            }
            s.insert(A[j]);
        }
    }
 
    // If we reach here, then no triplet was found
    return false;
}
void findPair(int nums[], int n, int target)
{
    // create an empty map
    unordered_map<int, int> map;
 
    // do for each element
    for (int i = 0; i < n; i++)
    {
        // check if pair (nums[i], target - nums[i]) exists
 
        // if the difference is seen before, print the pair
        if (map.find(target - nums[i]) != map.end())
        {
            cout << "Pair found (" << nums[map[target - nums[i]]] << ", "
                 << nums[i] << ")\n";
            return;
        }
 
        // store index of the current element in the map
        map[nums[i]] = i;
    }
 
    // we reach here if the pair is not found
    cout << "Pair not found";
}
//bruteforce approach O(n)
void findPairsum1(int arr[],int n,int target){

    // input  int nums[] = { 8, 7, 2, 5, 3, 1 };
    //output is 0and 2 is the pair of the array and  1and 4is the pair of the array 
    for(int i= 0;i<n;i++){
        for(int j= i+1;j<n;j++){
            if(arr[i]+arr[j] == target){
                cout<<i<<"and "<<j<<"is the pair of the array"<<" ";
            }
        }

    }
}
int findDuplicate(int arr[],int n){
      sort(arr,arr+n);
        
        for(int i=0;i<n-1;i++){
            if(arr[i] == arr[i+1]){
                    return arr[i];        
            }
        }
        return -1;
        
}

void cyclicRotate(int arr[],int n){

    //input is int arr[] = {1, 2, 3, 4, 5};
    //output is
    int x= arr[n-1]; 
    for(int i=n-1;i>0;i--){
            arr[i] = arr[i-1];
           
    }
    arr[0] = x;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
void intersectionOf(int arr1[],int arr2[],int m,int n){
        //input is //  int arr1[] = { 1, 2, 2, 2, 3 };
    // int arr2[] = { 2, 3, 4, 5 };
    //output is 2 3 
    int i=0;
    int j=0;
    while(i<m && j<n){
        if(arr1[i] < arr2[j]){
            
            i++;
        }
        else if(arr2[j]<arr1[i]){
            j++;
        }
        else{
            cout<<arr2[j]<<" ";
            i++;
            j++;
        }
    }
  
}
void findunionforduplicate(int arr1[],int arr2[],int m,int n){
    //  int arr1[] = { 1, 2, 2, 2, 3 };
    // int arr2[] = { 2, 3, 4, 5 };
            //output is 1 2 3 4 5
                int i=0;
                int j=0;
                while(i<m && j<n){
                    if(arr1[i]<arr2[j]){
                        cout<<arr1[i]<<" ";
                        i++;
                    }
                   else if(arr2[j]<arr1[i]){
                        cout<<arr2[j]<<" ";
                        j++;
                    }
                    else{
                        cout<<arr2[j]<<" ";
                        
                        j++;
                        i++;
                    }
                }
                while(i<m){
                    cout<<arr1[i]<<" ";
                    i++;
                }
                while(j<n){
                    cout<<arr2[j]<<" ";
                    j++;
                }


}
void unionofThearray(int arr1[],int arr2[],int m,int n){
            //   input of the arrays is int arr1[] = { 1, 2, 4, 5, 6 };
            //   int arr2[] = { 2, 3, 5, 7 };

            //output is 1 2 3 4 5 6 7 
                int i=0;
                int j=0;
                while(i<m && j<n){
                    if(arr1[i]<arr2[j]){
                        cout<<arr1[i]<<" ";
                        i++;
                    }
                   else if(arr2[j]<arr1[i]){
                        cout<<arr2[j]<<" ";
                        j++;
                    }
                    else{
                        cout<<arr2[j]<<" ";
                        
                        j++;
                        i++;
                    }
                }
                while(i<m){
                    cout<<arr1[i]<<" ";
                    i++;
                }
                while(j<n){
                    cout<<arr2[j]<<" ";
                    j++;
                }


}

int moveallNegative(int arr[],int n){
        //input int arr[] = {1 ,-1 ,-3 , -2, 7, 5, 11, 6 };
        //output is -1 -3 -2 1 7 5 11 6 
        int j=0;
        for(int i=0;i<n;i++){
                if(arr[i]<0){
                    swap(arr[i],arr[j]);
                    j++;
                }

        }
        for(int i=0;i<n;i++){
            cout<<arr[i]<<" ";
        }
}
int sortzero(int arr[],int n){
        //input int arr[] = { 0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1 };
        //output is {0 0 0 0 0 1 1 1 1 1 2 2 }

        int start =0;
        int end =n-1;
        int mid =0;
        while(mid<=end){
            if(arr[mid]==0){
                swap(arr[start],arr[mid]);
                start++;
                mid++;
            }
            else if(arr[mid]==1){
                
                mid++;
            }
            else if(arr[mid]==2){
                    swap(arr[mid],arr[end]);
                    end--;
            }
        }
        for(int i=0;i<n;i++){
            cout<<arr[i]<<" ";
        }
}
 
int swapAlternates(int arr[],int n){
    //input is 2, 3, 4, 10, 40 
    //output is 3 2 10 4 40 
    for(int i=0;i<n-1;i = i+2){
        swap(arr[i],arr[i+1]);
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
 void maxAndmin(int arr[],int n){
     //input is 2, 3, 4, 10, 40 
     //output is max element is 40and min element is 2 
        int min = arr[0];
        int max = arr[0];
        for(int i=0;i<n;i++){
            if(arr[i]<min){
                min = arr[i];
            }
            if(arr[i]>max){
                max = arr[i];
            }
        }
        cout<<"max element is "<<max <<"and min element is "<<min<<" ";
 }
 void reverseArray(int arr[],int n){

     //input is 2, 3, 4, 10, 40 
        //output is 40 10 4 3 2 
     int start = 0;
     int end =n-1;
     while(start <= end){
         int temp = arr[start];
         arr[start] = arr[end];
         arr[end] = temp;
         start++;
         end--;
     }
     for(int i=0;i<n;i++){
         cout<<arr[i]<<" ";
     }
    
 }

int linearsearch(int arr[], int n, int x)
{
    int i;
    for (i = 0; i < n; i++)
        if (arr[i] == x)
            return i;
    return -1;
}
 

int main(void)
{
  vector<int>arr = {2,1,-3,4,-1,2,1,-5,4};
    int n = sizeof(arr) / sizeof(arr[0]);
  
    cout << maxSubArray(arr) << "\n";
     
   
    return 0;
}