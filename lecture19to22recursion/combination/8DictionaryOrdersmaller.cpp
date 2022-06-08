// C++ program to implement
// the above approach

#include <bits/stdc++.h>
using namespace std;
vector<int> sortEvenOdd(vector<int>& nums) {
        vector<int> odd;
        vector<int> even;
        for(int i=0;i<nums.size();i++)
        {
            if(i%2==0)
                even.push_back(nums[i]);
            else if(i%2!=0)
                odd.push_back(nums[i]);
        }
        sort(even.begin(),even.end());
        sort(odd.begin(),odd.end());
        reverse(odd.begin(),odd.end());
        int j=0;
        int k=0;
        for(int i=0;i<nums.size();i++)
        {
            if(i%2!=0)
            {
                nums[i]=odd[j];
                j++;
            }
            else if(i%2==0)
            {
                nums[i]=even[k];
                k++;
            }
        }
        return nums;   
    }