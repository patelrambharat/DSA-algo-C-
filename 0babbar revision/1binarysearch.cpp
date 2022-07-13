#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;


//Implement Binary Search
int binarySearch(int arr[], int n, int target) {
    int start = 0;
    int end = n-1;

    int mid = start +(end - start)/2;

    while(start <= end) {
        int midElement = arr[mid];

        //element found
        if(midElement == target) {
            return mid;
        }

        //check in left part and neglect right part
        if(target < midElement) {
            end = mid - 1;
        }
        else{
            //check in right part and neglect left part
            start = mid+1;
        }

        mid = start +(end - start)/2;
    }
    return -1;
}

//Find Last Occurences of a element in sorted array
int lastOcc(int arr[], int n, int target) {
    int start = 0;
    int end = n-1;

    int mid = start +(end - start)/2;
    int ans = -1;
    while(start <= end) {
        int midElement = arr[mid];

        //element found
        if(midElement == target) {
            ans = mid;
            start = mid+1;
        }

        //check in left part and neglect right part
        if(target < midElement) {
            end = mid - 1;
        }
        else{
            //check in right part and neglect left part
            start = mid+1;
        }

        mid = start +(end - start)/2;
    }
    return ans;
}

//find first occurences of an element in sorted array
int firstOcc(int arr[], int n, int target) {
    int start = 0;
    int end = n-1;

    int mid = start +(end - start)/2;
    int ans = -1;
    while(start <= end) {
        int midElement = arr[mid];

        //element found
        if(midElement == target) {
            ans = mid;
            end = mid - 1;
        }

        //check in left part and neglect right part
        if(target < midElement) {
            end = mid - 1;
        }
        else{
            //check in right part and neglect left part
            start = mid+1;
        }

        mid = start +(end - start)/2;
    }
    return ans;
}

//find fixed point (Index = Value) in a sorted array
int getFixedPoint(int arr[], int n) {
    int s = 0;
    int e = n-1;

    while(s <= e) {
        int mid = (s+e)/2;
        if(arr[mid] == mid)
            return mid;

        if(arr[mid] > mid) {
            e = mid - 1;
        }    
        else{
            s = mid + 1;
        }
    }
    return -1;
}

//Find Pivot in an sorted and rotated array
//gives the element which is greater than both prev or next element
int findPivot(int arr[], int n) {
    int s = 0;
    int e = n-1;

    while(s <= e) {
        int mid = (s+e)/2;

        if(arr[mid] > arr[mid+1])//also check mid
            return mid;
        if(arr[mid] < arr[mid-1]) //also check mid in range or not
            return mid-1;
        
        if(arr[s] >= arr[mid])
            e = mid - 1;
        else
            s = mid + 1;
    }
    return -1;
}

//find Sqrt using Binary Search
double getSqrt(int num, int precision) {
    int s = 0;
    int e = num;
    double ans = -1;
    while(s <= e) {
        
        int mid = (s+e)/2;
        
        if(mid*mid == num)
            return mid;
        if ((mid*mid) < num && ((mid + 1)*(mid + 1) > num))
		{ //imp condition
			ans = mid;
			break;
		}
        else if(mid*mid < num) {
            s = mid+1;
        }
        else{
            e = mid - 1;
        }
    }
    
    double factor = 1;
    double j;
    for(int i=0; i<precision; i++) {
        factor = factor/10;
        for(j = ans; j*j <=num; j += factor) {
            ans = j;
        }
    }
    return ans;
}

//find Peak in a mountain
int findPeak(int arr[], int n ) {
    int s = 0, e = n-1;

    while(s < e ) {
        int mid = (s+e)/2;

        if(arr[mid] < arr[mid+1])
            s = mid + 1;
        else
            e = mid;
    }
    return s;
}

//code for find N and its Double Problem
bool binarySearch(vector<int> &arr, int s, int e, int target) {
        //cout << s << " " << e << " " << target << endl;
        int mid = s + (e-s)/2;
        while(s <= e) {
            //cout << "value of mid " << mid << " and target " << target << endl;
            if(target == arr[mid])
                return true;
            
            if(arr[mid] > target)
                e = mid - 1;
            else
                s = mid + 1;
            mid = s + (e-s)/2;
        }
        return false;
    }

bool checkIfExist(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        for(int i=0; i<arr.size(); i++) {
            //positive number
            if(arr[i] >= 0 && binarySearch(arr,i+1, arr.size()-1, 2*arr[i]) )
                return true; 
            //negative number
            if( arr[i] < 0 && arr[i]%2 == 0 && binarySearch(arr, i+1, arr.size()-1, arr[i]/2))
                return true;
        }
        return false;
}

//code for find element in a sorted array of unknown size

int binarySearch(int arr[], int s, int e, int target) {
    int mid = s + (e-s)/2;

    while(s <= e) {
        if(arr[mid] == target)
            return mid;
        if(arr[mid] > target)
            e = mid - 1;
        else
            s = mid + 1;
        mid = s + (e-s)/2;    
    }
    return -1;
}

//we dont know the size of array, 
// considering it infinite as per question
//assumption array size if infinite, so no Index Out of Bound Exception
int findPosition(int arr[], int target) {
    int s = 0, e = 1;
    int val = arr[s];

    while(val < target) {
        s = e;
        e = 2*e;
        val = arr[e];
    }

    return binarySearch(arr, s, e, target);
}

int main() {
    cout << getSqrt(25,3) << endl;
    
    int arr[] = {2,4,6,8,9,11,23};
    int n = 7;
    int target = 23;

    cout << binary_search(arr, arr + n, target) << endl;

    cout << binarySearch(arr, n, target) << endl;
    return 0;
}