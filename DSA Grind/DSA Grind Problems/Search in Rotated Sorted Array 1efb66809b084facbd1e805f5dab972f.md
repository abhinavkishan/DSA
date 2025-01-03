# Search in Rotated Sorted Array

Tags: Arrays, Binary Search
Date: August 22, 2023
Level: Medium
Number: 23
Platform: Leetcode

# **Approach:**

- The solution provided in the code implements two approaches, Brute force and Binary search.
    - The Brute force approach:
        1. Iterates through the array and checks if the current element is equal to the target. If it is, then it returns the index of that element, otherwise, it returns -1. This approach has a time complexity of O(n).
    - The Binary search approach is based on the fact that a rotated sorted array can be divided into two sorted arrays.
        1. The approach starts with finding the mid element and compares it with the target element.
        2. If they are equal, it returns the mid index. If the left half of the array is sorted, then it checks if the target lies between the start and the mid, and updates the end pointer accordingly.
        3. Otherwise, it checks if the target lies between mid and end, and updates the start pointer accordingly.
        4. If the right half of the array is sorted, then it checks if the target lies between mid and end, and updates the start pointer accordingly.
        5. Otherwise, it checks if the target lies between start and mid, and updates the end pointer accordingly.
        6. This process continues until the target element is found, or the start pointer becomes greater than the end pointer, in which case it returns -1.
        7. This approach has a time complexity of O(log n).

# **Complexity:**

- Time Complexity:
    1. The time complexity of the Brute force approach is O(n), where n is the size of the input array.
    2. The time complexity of the Binary search approach is O(log n), where n is the size of the input array.
- Space Complexity:
    
    The space complexity of both approaches is O(1) as we are not using any extra space to store any intermediate results.
    
    ```cpp
    class Solution {
    public:
        int search(vector<int>& nums, int target) {
            int n = nums.size();
            int i = 0, j = n - 1;
            while(i <= j) {
                int mid = i + (j - i) / 2;
                if(nums[mid] == target) return mid;
                // checking which part is sorted
                if(nums[i] <= nums[mid]) {
                    if(nums[i] <= target && nums[mid] > target) {
                        j = mid - 1;
                    } else {
                        i = mid + 1;
                    }
                } else {
                    if(nums[mid] < target && nums[j] >= target) {
                        i = mid + 1;
                    } else {
                        j = mid - 1;
                    }
                }
            }
            return -1;
        }
    };
    ```