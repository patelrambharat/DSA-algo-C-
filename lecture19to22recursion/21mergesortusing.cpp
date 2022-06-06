#include<iostream>
using namespace std;
void merge(int arr[],int s,int e){
    int mid = (s+e)/2;

    int len1 = mid -s+1;
    int len2 = e - mid;

    int *first = new int[len1];  //create two arrays
    int *second = new int[len2];

    //copy values

    int mainArrayIndex = s;  //start to mid  wala 
    for(int i=0;i<len1;i++){
        first[i] = arr[mainArrayIndex++];
    }
    mainArrayIndex = mid +1;  //mid +1 to end wala
    for(int i=0;i<len2;i++){
        second[i] = arr[mainArrayIndex++];
    }

    //merge two sorted array

    int index1=0;
    int index2=0;
    mainArrayIndex =s;
    while(index1 < len1 && index2 <len2){

        if(first[index1] < second[index2]){
            arr[mainArrayIndex++] = first[index1++];
        }
        else{
            arr[mainArrayIndex++] = second[index2++];
        }
    }
    while(index1 < len1){
        arr[mainArrayIndex++] =first[index1++];
    }
    while(index2 < len2){
        arr[mainArrayIndex++] = second[index2++];
    }
    delete []first;
    delete []second;


}
void mergesort(int arr[],int s,int e){

    //base case 
    if(s>=e){
        return ;
    }
    int mid = (s+e)/2;

    //left part sort karna hai
    mergesort(arr,s,mid);
    //right part sort karna hai
    mergesort(arr,mid+1,e);

    //merge
    merge(arr,s,e);
}
void printArray(int A[], int size)
{
    for (auto i = 0; i < size; i++)
        cout << A[i] << " ";
}
  
// Driver code
int main()
{
    int arr[] = { 12, 11, 13, 5, 6, 7 };
    auto arr_size = sizeof(arr) / sizeof(arr[0]);
  
    cout << "Given array is \n";
    printArray(arr, arr_size);
  
    mergesort(arr, 0, arr_size - 1);
  
    cout << "\nSorted array is \n";
    printArray(arr, arr_size);
    return 0;
}
  