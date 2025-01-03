#include <bits/stdc++.h>
using namespace std;

void selectionSort(vector<int> nums)
{
    // TC: O(n^2)
    // SC: O(1)
    int n = nums.size();
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for (int j = i; j < n; j++)
        {
            if (nums[j] < nums[minIndex])
                minIndex = j;
        }
        swap(nums[i], nums[minIndex]);
    }
    cout << "Sorted array using selection sort: ";
    for(auto i: nums)
        cout << i << " ";
    cout << endl;    
}

void bubbleSort(vector<int> nums) {
    // TC: O(n^2)
    // SC: O(1)
    // best case: O(n) when array is already sorted
    int n = nums.size();
    for(int i = n - 1; i >= 1; i--) {
        bool didSwap = 0;
        for(int j = 0; j < i; j++) {
            if(nums[j] > nums[j + 1]) {
                swap(nums[j], nums[j + 1]);
                didSwap = 1;
            }
        }
        if(!didSwap) break;
    }
    cout << "Sorted array using bubble sort: ";
    for(auto i: nums)
        cout << i << " ";
    cout << endl;    
}

void insertionSort(vector<int> nums) {
    // TC: O(n^2)
    // SC: O(1)
    // best case: O(n) when array is already sorted
    for(int i = 1; i < nums.size(); i++) {
        int j = i;
        while(j > 0 && nums[j - 1] > nums[j]) {
            swap(nums[j - 1], nums[j]);
            j--;
        }
    }
    cout << "Sorted array using insertion sort: ";
    for(auto i: nums)
        cout << i << " ";
    cout << endl;
}

void recursiveBubbleSort(vector<int> &nums, int n) {
    // TC: O(n^2)
    // SC: O(n) for recursive stack
    if(n == 1) return;
    int swaps = 0;
    for(int i = 0; i < n - 1; i++) {
        if(nums[i] > nums[i + 1]) {
            swap(nums[i], nums[i + 1]);
            swaps++;
        }
    }
    if(swaps == 0) return;
    recursiveBubbleSort(nums, n - 1);
}

void recursiveInsertionSort(vector<int> &nums, int n) {
    // TC: O(n^2)
    // SC: O(n) for recursive stack
    if(n == 1) return;
    recursiveInsertionSort(nums, n - 1);
    int j = n - 1;
    while(j > 0 && nums[j - 1] > nums[j]) {
        swap(nums[j - 1], nums[j]);
        j--;
    }
}

int main()
{
    vector<int> nums = {5, 4, 3, 2, 1};
    cout << "Original array: ";
    for(auto i: nums)
        cout << i << " ";
    cout << endl;
    selectionSort(nums);

    bubbleSort(nums);

    vector<int> nums2(nums);
    recursiveBubbleSort(nums2, nums.size());
    cout << "Sorted array using recursive bubble sort: ";
    for(auto i: nums2)
        cout << i << " ";
    cout << endl;
    insertionSort(nums);
    vector<int> nums3(nums);
    recursiveInsertionSort(nums3, nums.size());
    cout << "Sorted array using recursive insertion sort: ";
    for(auto i: nums3)
        cout << i << " ";
    cout << endl;
    return 0;
}