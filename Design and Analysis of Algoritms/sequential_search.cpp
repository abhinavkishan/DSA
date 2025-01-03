#include <iostream>
#include <vector>
#define MAX 10
using namespace std;

int seq_search(vector<int>arr, int n, int key) {
    for(int i = 0; i < n; i++) {
        if(arr[i] == key) {
            return i;
        }
    }
}

int main() {
    vector<int> arr;
    int i, n, key;
    cout << "Enter the number of elements: ";
    cin >> n;
    arr.resize(n);
    cout << "Enter the elements: ";
    for(i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << "Enter the key: ";
    cin >> key;
    int pos = seq_search(arr, n, key);
    if(pos == -1) {
        cout << "Key not found" << endl;
    } else {
        cout << "Key found at position " << pos << endl;
    }
}