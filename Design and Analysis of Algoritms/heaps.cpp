#include <bits/stdc++.h>
using namespace std;

class Heap {
    private:
        int *arr;
        int capacity;
        int size;
    public:
        Heap(int size = 0): capacity(size), arr(new int[size]), size(0) {}
        Heap(int *arr, int size): capacity(size), size(size) {
            this->arr = new int[size];
            for(int i = 0; i < size; i++) {
                this->arr[i] = arr[i];
            }
            for(int i = size / 2 - 1; i >= 0; i--) {
                heapify(i);
            }
        }
        ~Heap() { delete[] arr; }

        void heapify(int i) {
            int l = left(i);
            int r = right(i);
            int largest = i;
            if(l < size && arr[l] > arr[i]) {
                largest = l;
            }
            if(r < size && arr[r] > arr[largest]) {
                largest = r;
            }
            if(largest != i) {
                swap(arr[i], arr[largest]);
                heapify(largest);
            }
        }

        int insert(int x) {
            if(size == capacity) {
                return -1;
            }
            arr[size] = x;
            size++;
            int i = size - 1;
            while(i != 0 && arr[parent(i)] < arr[i]) {
                swap(arr[parent(i)], arr[i]);
                i = parent(i);
            }
            return 0;
        }

        int pop() {
            if(size == 0) {
                return -1;
            }
            int root = arr[0];
            arr[0] = arr[size - 1];
            size--;
            heapify(0);
            return root;
        }

        int parent(int i) {
            return (i - 1) / 2;
        }
        int left(int i) {
            return 2 * i + 1;
        }
        int right(int i) {
            return 2 * i + 2;
        }
        int getTop() {
            return arr[0];
        }

        int len() {
            return size;
        }
        bool empty() {
            return size == 0;
        }

        void print() {
            for(int i = 0; i < size; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
};

int main()
{
    Heap h(10);
    h.insert(10);
    h.insert(20);
    h.insert(30);
    h.print();
    cout << "Max element: " << h.pop() << endl;
    h.print();

    int arr[] = {10, 20, 30, 40, 50};
    Heap h2(arr, 5);
    h2.print();
    cout << "Max element: " << h2.pop() << endl;
    h2.print();
    return 0;
}