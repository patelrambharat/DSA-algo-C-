#include<bits/stdc++.h>
using namespace std;
bool isSubset(int arr1[],int arr2[],int m,int n){
    unordered_map<int,int>mp;
    for(int i=0;i<n;i++){
            mp[arr1[i]] = 1;
    }
    for(int j=0;j<m;j++){
        if(mp[arr2[j]] != 1){
            return "No";
        }
    }
    return "Yes";
}

#define MAX 500

void majorityElement(int arr[],int n){
    unordered_map<int ,int >mp;
    int cnt=1;
    for(int i=0;i<n;i++){
        mp[arr[i]]++;
    }
    for(auto i:mp ){
        if(i.second > n/2){
            cnt =1;
            cout<<"majority element fount "<<i.first<<endl;
            break;
        }
        if(cnt ==0){
            cout<<"no majority element ";
        }
    }
}
 int getMinDiff(int arr[], int n, int k) {
        // code here
        sort(arr,arr+n);
          int mini = arr[0];
    int maxi = arr[n-1];
    int ans =maxi -mini;
    for(int i=0;i<n;i++){
        mini = min(arr[0]+k,arr[i]-k);
        maxi = max(arr[n-1]-k,arr[i-1]+k);
        if(mini<0) continue;
        ans = min(maxi - mini ,ans);
    }
    return ans;
    }
int minimunPlatform(int arr[],int dept[],int n){
    sort(arr,arr+n);
    sort(dept,dept+n);
    int platform  = 1,res =1;
    int i=1,j=0;
    while(i<n && j<n){
        if(arr[i] <= dept[j]){
            platform++;
            i++;
        }
        else if(arr[i]>dept[j]){
            platform--;
            j++;
        }
        if(platform > res){
            res = platform;
        }

    }
    return res;
}
int multiply(int x,int res[],int res_size)
{
            int carry =0;
            for(int i=0;i<res_size;i++){
                int prod = res[i] *x+carry;
                res[i] = prod %10;
                carry = prod /10;

            }
            while(carry){
                res[res_size] = carry %10;
                carry = carry/10;
                res_size++;
            }
            return res_size;
}
void factoriaclOfalargeNumber(int n){
        int res[MAX];
        res[0] = 1;
        int res_size = 1;
        for(int x=2;x<=n;x++){
            res_size = multiply(x,res,res_size);
         }
         cout<<"factorial of given number is"<<" ";
         for(int i=res_size-1;i>=0;i--){
             cout<<res[i]<<" ";
         }
}
// efficient approach
bool subArrayExists(int arr[], int n) {
    unordered_map<int,int>mp;
    int sum =0;
    for(int i=0;i<n;i++){
        sum += arr[i];
        if(mp[sum] or arr[i] == 0 or sum == 0){
            return true;
        }
        mp[sum]++;
    }
    return false;
}
// bruteforce approach
bool subArrayExist(int arr[], int n) {
    for(int i=0; i<n; i++) {
     int sum = 0;
     for(int j=i; j<n; j++) {
      sum += arr[j];
      if(sum == 0) {
       return true;
      }
     }
    }
    return false;
}
long long int  equalZeroandOne(int arr[],int n){
        long long ans =0,cnt =0;
        unordered_map<long long,long long >mp;
        mp[0] =1;
        for(int i=0;i<n;i++){
            cnt += (arr[i] == 1 ? 1 : -1);
            ans += mp[cnt];
            mp[cnt]++;
        }   
        return ans;
}

void printFirstNonrepeating(int arr[],int n){
    // input is int arr[] = {10, 5, 3, 4, 3, 5, 6};
    unordered_map<int,int>mp;
    for(int i=0;i<n;i++){
        mp[arr[i]]++;
    }
    for(int i=0;i<n;i++){
        if(mp[arr[i]] ==1){
            cout<<"first non repeating element is "<<arr[i];
            return;
        }
    }
}
void printFirstRepeating(int arr[],int n){

// input is int arr[] = {10, 5, 3, 4, 3, 5, 6};
 
//     int n = sizeof(arr) / sizeof(arr[0]);
//     printFirstRepeating(arr, n);

    int min  = -1;
    set<int>st;
    for(int i=n-1;i>=0;i--){
        if(st.find(arr[i]) != st.end()){
            min = i;

        }
        else 
        {
            st.insert(arr[i]);
        }
    }
    if(min != -1){
        cout<<"the first repeating element is"<<arr[min];
    }
    else{
        cout<<"there is no repeating element";
    }
    
    }
//efficient solution 
 vector <int> commonElements (int a[], int b[], int c[], int n1, int n2, int n3)
        {
            //code here.
            int i=0,j=0,k=0;
            vector<int>v;
            while(i<n1 and j<n2 and k<n3){
                if(a[i]== b[j] and b[j] == c[k]){
                    v.push_back(a[i]);
                    i++,j++,k++;
                }
                else if(a[i] < b[j])
                {
                    i++;
                }
                else if(b[j]<c[k]){
                    j++;
                }
                else{
                    k++;
                }
                int xx = a[i-1];
                while(a[i]==xx){
                    i++;
                }
                int yy = b[j-1];
                while(b[j]==yy){
                    j++;
                }
                int zz = c[k-1];
                while(c[k] == zz){
                    k++;
                }
            }
            if(v.size()==0){
                return {-1};
            }
            return v;
        }
void findCommon(int arr1[],int arr2[],int arr3[],int n1,int n2,int n3){
        //time and space both O(n1 + n2 + n3).
    //this is the input element  int ar1[] = { 1, 5, 10, 20, 40, 80 };
    // int ar2[] = { 6, 7, 20, 80, 100 };
    // int ar3[] = { 3, 4, 15, 20, 30, 70, 80, 120 };

    unordered_map<int ,int >m1,m2,m3;
    for(int i=0;i<n1;i++)   m1[arr1[i]]++;
    for(int i=0;i<n2;i++)   m2[arr2[i]]++;
    for(int i=0;i<n3;i++)   m3[arr3[i]]++;

    vector<int>v;
    for(int i=0;i<n1;i++){
        if(m1[arr1[i]] and m2[arr1[i]] and m3[arr1[i]]){
            v.push_back(arr1[i]);
            m1[arr1[i]] = 0;          //because it not repeate the same element 

        }
    }
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";

    }
    
}
int main(){
    
  int arr1[] = { 11, 1, 13, 21, 3, 7 };
    int arr2[] = { 11, 3, 7, 1 };
 
    int m = sizeof(arr1) / sizeof(arr1[0]);
    int n = sizeof(arr2) / sizeof(arr2[0]);
 
    if (isSubset(arr1, arr2, m, n))
        printf("arr2[] is subset of arr1[] ");
    else
        printf("arr2[] is not a subset of arr1[]");
 
    getchar();
    return 0;
    
}