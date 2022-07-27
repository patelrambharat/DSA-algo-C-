#include<iostream>
using namespace std;

bool cmp(pair<int,int>& a, pair<int,int>& b){

    if(a.first != b.first) {
        //sort according to first value
        return a.first < b.first;
    }
    else{
        //sort according to second value
        return a.second < b.second;
    }
}


int main() {
    pair<int,int> arr[10];
    arr[0] = make_pair(12, 8);
    arr[1] = make_pair(10, 2);
    arr[2] = make_pair(9, 1);
    arr[3] = make_pair(8, 6);
    arr[4] = make_pair(7, 12);
    arr[5] = make_pair(9, 13);
    arr[6] = make_pair(8, 5);
    arr[7] = make_pair(12, 7);
    arr[8] = make_pair(4, 14);
    arr[9] = make_pair(3, 17);


    sort(arr, arr+10, cmp);

    for( int i=0; i<10; i++ ){
        pair<int,int> a = arr[i];
        cout << a.first << " " << a.second << endl;
    }

}