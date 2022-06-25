// 1723. Find Minimum Time to Finish All Jobs
// Hard

// 580

// 15

// Add to List

// Share
// You are given an integer array jobs, where jobs[i] is the amount of time it takes to complete the ith job.

// There are k workers that you can assign jobs to. Each job should be assigned to exactly one worker. The working time of a worker is the sum of the time it takes to complete all jobs assigned to them. Your goal is to devise an optimal assignment such that the maximum working time of any worker is minimized.

// Return the minimum possible maximum working time of any assignment.

 

// Example 1:

// Input: jobs = [3,2,3], k = 3
// Output: 3
// Explanation: By assigning each person one job, the maximum time is 3.
// Example 2:

// Input: jobs = [1,2,4,7,8], k = 2
// Output: 11
// Explanation: Assign the jobs the following way:
// Worker 1: 1, 2, 8 (working time = 1 + 2 + 8 = 11)
// Worker 2: 4, 7 (working time = 4 + 7 = 11)
// The maximum working time is 11.
 class Solution {
public:
    bool check(vector<int>&nums,vector<long long>&vec,int step,long long val)
    {
        if(step>=nums.size()) return true;
        long long cur=nums[step];
        for(int i=0;i<vec.size();i++)
        {
            if(cur+vec[i]<=val)
            {
                vec[i]+=cur;
                if(check(nums,vec,step+1,val)) return true;
                vec[i]-=cur;
            }
            if(vec[i]==0) break;
        }
        return false;
    }
    int minimumTimeRequired(vector<int>& nums, int k) {
        long long l=*max_element(nums.begin(),nums.end());
        long long r=accumulate(nums.begin(),nums.end(),0);
        while(l<r)
        {
            long long mid=(l+r)/2;
            vector<long long>vec(k,0);
            if(check(nums,vec,0,mid))
            {
                r=mid;
            }
            else
                l=mid+1;
        }
        return l;
    }
};