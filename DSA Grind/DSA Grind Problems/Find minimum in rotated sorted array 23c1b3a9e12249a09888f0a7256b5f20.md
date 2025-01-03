# Find minimum in rotated sorted array

Tags: Arrays, Binary Search
Level: Medium
Number: 22

# **Intuition:**

The code aims to find the minimum element in a rotated sorted array. It utilizes the binary search algorithm to efficiently narrow down the search space and locate the minimum element.

# **Approach:**

1. Initialize two pointers, `left` and `right`, representing the start and end indices of the search space.
2. Enter a while loop as long as `left` is less than `right`.
3. Calculate the midpoint `mid` using the formula `mid = left + (right - left) / 2`.
4. Compare the value at index `mid` with the value at index `right` to determine which half of the array contains the minimum element.
    - If `nums[mid] > nums[right]`, it means the minimum element lies in the right half of the array. Update `left = mid + 1` to search in the right half.
    - Otherwise, the minimum element lies in the left half of the array, including the `mid` index. Update `right = mid` to search in the left half.
5. Repeat steps 3-4 until the search space is narrowed down to a single element, i.e., `left >= right`.
6. Return the value at `nums[left]` as the minimum element.

# **Complexity:**

- Time Complexity: The binary search approach has a time complexity of O(log n), where n is the size of the input array `nums`. The search space is halved in each iteration, leading to efficient searching.
- Space Complexity: The code has a space complexity of O(1) as it uses a constant amount of extra space for the variables `left`, `right`, and `mid`. No additional data structures are used that scale with the input size.
- in first case when nums[mid] > nums[high] , it can not be a minimum value because it is already greater than one value (nums[high]) , but in second case when nums[mid]< num[high] it is possible that mid is the minimum value for example 4 5 1 2 3 , here mid is 1 and it is less than last value.

```cpp
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int  i = 0, j = n - 1;
        while(i < j) {
            if(nums[i] <= nums[j]) return nums[i];
            int mid = i + (j - i) / 2;
            if(nums[mid] > nums[j]) i = mid + 1;
            else j = mid;
        } 
       
        return nums[i];
    }
};
```