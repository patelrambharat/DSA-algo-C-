#include <iostream>
#include <vector>
#include <algorithm>
typedef long long int ll;
using namespace std;
bool isPossiblecow(vector<int>&stalls,int k,int mid){
    
    int cowCount = 1;
    int lastPos =stalls[0];
    for(int i=0;i<stalls.size();i++){
        if(stalls[i] - lastPos >= mid){
            cowCount++;
        
        if(cowCount ==k)
        {
            return true;
        }
        lastPos = stalls[i];
    }
    }
    return false;
}
int aggresiveCow(vector<int>&stalls,int k){
    sort(stalls.begin(),stalls.end());
    int s =0;
    int maxi =-1;
    for(int i=0;i<stalls.size();i++){
        maxi = max(maxi , stalls[i]);
    } 
    int e = maxi;
    int ans = -1;
    while(s <= e){
        int mid = (s+e)/2;
        if(isPossiblecow(stalls,k,mid)){
            ans = mid;
            s = mid+1;
        }
        else {
            e = mid -1;
        }

    }
    return ans;
}
bool isPossiblelforpainter(int arr[],int n,int m,int mid){
        int painterCount = 1;
        int borderSection =0;
        for(int i=0;i<n;i++){
            if(borderSection + arr[i] <= mid){
                borderSection += arr[i];
            }
            else{
                painterCount++;
                if(painterCount > m || arr[i] > mid){
                    return false;
                }
                borderSection = arr[i];
            }
        }
        return true;
}
int painterProblem(int arr[],int n,int m){
    int s=0;
    int sum =0;
    for(int i=0;i<n;i++){
        sum += arr[i];
    }
    int e = sum;
    int ans = -1;
    while(s<=e){
        int mid = (s+e)/2;
        if(isPossiblelforpainter(arr,n,m,mid)){
            ans = mid;
            e = mid-1;
        }
        else
        {
                s = mid+1;
        }    
        }
        return ans;
}

bool isPossible(int arr[],int n ,int m ,int mid){
        int studentCnt = 1;
        int pageSum =0;
        for(int i=0;i<n;i++){
            if(pageSum+arr[i] <= mid){  //if pagesum is less or equal to mid then isko sum kr lete hai
                pageSum += arr[i];
            }
            else{
                studentCnt++;   //nhi to nye student ko add kr lete hai
                //ab check karenge ki student count bada to nhi n ho gya
                if(studentCnt > m || arr[i] > mid){
                    return false;
                 }
                pageSum = arr[i];   //page sum ki value bhi to badhani padegi n jo ki 0 se start hogi 
                }
            }
      
      return true;
}
int bookAllocationProblem(int arr[],int n,int m){
    int s = 0;
    int sum =0;
    for(int i=0;i<n;i++){
        sum += arr[i];
    }
    int e = sum;
    int ans = -1;
    while(s<=e){
        int mid = (s+e)/2;
        if(isPossible(arr,n,m,mid)){
            ans = mid;
            e = mid -1;
        }
        else{
            s = mid +1;
        }
    }
    return ans;
    }
bool isValid(vector<ll > v, ll p,int time)
{
    ll sum = 0;
    for (ll i = 0; i < v.size(); i++)// this loop will give no. of paratha made in the specified time
    {
        int t = time;
        int count = 0,k=1;
        while (t>0)
        {
            t = t - k*v[i];
            if (t >= 0)
            {
                count++;
                k++;
            }
        }
        sum += count;
        //cout << count << endl;
    }
    //cout << "parathas made " << sum << endl;
    if (sum < p)
        return false;
    return true;

}

ll check_ans(vector<ll> v, ll p)
{
    ll s = 0, e = (v[0] * p*(p + 1)) / 2;// we can consider the maximum time taking that all th parathas are cooked by the first cook
    ll mid = (s + e) / 2;
    ll  ans;
    while (s <= e)
    {
        //cout << s << " " << e << " " << mid << endl;
        if (isValid(v,p,mid))
        {
            //cout << "valid"<<endl<<endl;
            ans = mid;
            e = mid - 1;
        }
        else
        {
        //    cout << "not valid" << endl;
            s = mid + 1;
        }
        mid = (s + e) / 2;
    }
    return ans;
}

// int main()
// {
//     ll p, size;
//     cin >> p >> size;
//     vector<ll> v;
//     while (size--)
//     {
//         int d;
//         cin >> d;
//         v.push_back(d);
//     }
//     sort(v.begin(), v.end());
//     ll ans = check_ans(v, p);
//     cout << ans << endl;

//     return 0;
// }

bool ispossible(int mid,int arr[],int n,int target ){
    int sum =0;
    
        for(int i=0;i<n;i++){
            int diff =0;
            if(arr[i]> mid ){
                diff = arr[i] - mid;
            }
            sum = sum + diff;
        }
       
    
     if(sum >=target){
            return true;
        }
        else {
            return false;
        }
}
int findmaxheightofaari(int arr[],int n,int target){
    
    sort(arr,arr+n);
    int start =0;
    int end = arr[n-1];
    int ans = -1;
    while(start<=end){
        int mid = (start+end)/2;
        if(ispossible(mid,arr,n,target)){
            ans = mid;
            start = mid+1;  //going to upper side of the tree
        }
        else{
            end = mid -1;  //going to right side of the tree means niche jayenge
        }
    }
    return ans;
}
int main(){
    vector<int>arr = {4,2,1,3,6};
    
    int k = 2;
    cout << aggresiveCow(arr, k) << endl;
 
    return 0;
}