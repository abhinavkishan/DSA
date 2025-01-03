#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& arr, int l, int mid, int r) {
    int s1 = mid - l + 1;
    int s2 = r - mid;
    int left[s1], right[s2];
    for(int i = 0; i < s1; i++) {
        left[i] = arr[l + i];
    }
    for(int i = 0; i < s2; i++) {
        right[i] = arr[mid + 1 + i];
    }
    int i = 0, j = 0, k = l;
    while(i < s1 && j < s2) {
        if(left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        } else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }
    while(i < s1) {
        arr[k] = left[i];
        i++;
        k++;
    }

    while(j < s2) {
        arr[k] = right[j];
        j++;
        k++;
    }
}

void merge_sort(vector<int>& arr, int l, int r) {
    if(l < r) {
        int mid = (l + r) / 2;
        merge_sort(arr, l, mid);
        merge_sort(arr, mid + 1, r);
        merge(arr, l, mid, r);
    }
}

int main() {
    vector<int> arr = {1,3,2,3,4,5};
    int n = arr.size();
    merge_sort(arr, 0, n - 1);
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
}