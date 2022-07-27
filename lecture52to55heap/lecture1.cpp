
#include<iostream>
using namespace std;

class Heap {
    public:
        int arr[250];
        int size;

        Heap() {
            size = 0;
        }

        void insertIntoHeap(int val) {
            //we want to insert a value
            size = size + 1;
            int index = size;

            //insert value
            arr[index] = val;

            //take val to its right position

            while(index > 1) {

                int parentIndex = index/2;

                if(arr[parentIndex] < arr[index]) {
                    swap(arr[parentIndex], arr[index]);
                    index = parentIndex;
                }
                else{
                    break;
                }
            }
        }

        void print() {
            for(int i=1; i<=size; i++) {
                cout << arr[i] <<" ";
            }cout << endl;
        }

        void deleteFromHeap() {
            if(size == 0) {
                cout << "heap is already empty" << endl;
                return;
            }

            //step1: 
            swap(arr[1], arr[size]);

            //step2:
            size--;

            //step3:
            int index = 1;

            while(index <=size ) {
                int largest = index;
                int left = 2*index;
                int right = 2*index + 1;

                if(left <= size && arr[left] > arr[largest] ) {
                    largest = left;
                }
                if(right <= size && arr[right] > arr[largest] ) {
                    largest = right;
                } 

                if(largest != index) {
                    swap(arr[index], arr[largest]);
                    index = largest;
                }
                else{
                    //agar largest change nahi hua, iska matlab correct pos pr aa chuke ho
                    break;
                }
            }

        }
};

int main() {

    Heap maxheap;
    
    maxheap.insertIntoHeap(2);
    maxheap.insertIntoHeap(6);
    maxheap.insertIntoHeap(8);
    maxheap.insertIntoHeap(3);
    maxheap.insertIntoHeap(7);

    maxheap.print();

    maxheap.deleteFromHeap();
    maxheap.print();
    
    maxheap.deleteFromHeap();
    maxheap.print();
    
    maxheap.deleteFromHeap();
    maxheap.print();
    
    maxheap.deleteFromHeap();
    maxheap.print();

    maxheap.deleteFromHeap();
    maxheap.print();

    maxheap.deleteFromHeap();
    maxheap.print();


    return 0;
}
