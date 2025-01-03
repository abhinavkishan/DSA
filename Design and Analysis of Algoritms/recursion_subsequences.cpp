#include <bits/stdc++.h>
using namespace std;

void getSubsequences(int idx, int arr[], int n, vector<int>& taken) {
    if(idx == n) {
        for(int i = 0; i < taken.size(); i++) {
            cout << taken[i] << " ";
        }
        cout << endl;
        return;
    }
    // for reverse order do not take the element first
    // take the element
    taken.push_back(arr[idx]);
    getSubsequences(idx + 1, arr, n, taken);
    taken.pop_back();

    // don't take the element
    getSubsequences(idx + 1, arr, n, taken);
    // time: O(2^n)
    // space: O(n)
}

int main() {
    int arr[] = {3, 1, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    vector<int> taken;
    getSubsequences(0, arr, n, taken);
}