# Maximum Product Subarray

Tags: Arrays, Dynamic Programming
Date: September 3, 2023
Level: Medium
Number: 27
Platform: Leetcode

```cpp
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int prefix_p = 1, suffix_p = 1;
        int max_p = INT_MIN;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            prefix_p *= nums[i];
            suffix_p *= nums[n - i - 1];
            max_p = max(max_p, max(prefix_p, suffix_p));
            if(prefix_p == 0) prefix_p = 1;
            if(suffix_p == 0) suffix_p = 1;
        }
        return max_p;
    }
};
```