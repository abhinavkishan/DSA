# Product of array except self

Tags: Arrays, prefix sum
Level: Medium
Number: 10
Platform: Leetcode

```cpp
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);
        vector<int> leftp(n);
        vector<int> rightp(n);
        leftp[0] = 1, rightp[n - 1] = 1;
        for(int i = 1; i < n; i++) {
            leftp[i] = leftp[i-1] * nums[i-1];
        }
        for(int i = n - 2; i >= 0; i--) {
            rightp[i] = rightp[i + 1] * nums[i + 1];
        }
        for(int i = 0; i < n; i++) {
            res[i] = leftp[i] * rightp[i];
        }
        return res;
    }
};
```

```cpp
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n,1);

        int leftp = 1, rightp = 1;  

        for(int i = 0; i < n; i++) {
            res[i] *= leftp;
            res[n - 1 - i] *= rightp;
            leftp *= nums[i];
            rightp *= nums[n - 1 - i];
        }
        return res;
    }
};
```