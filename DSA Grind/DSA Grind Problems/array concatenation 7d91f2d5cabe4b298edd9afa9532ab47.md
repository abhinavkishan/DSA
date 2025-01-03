# array concatenation

Tags: Arrays
Level: Easy
Number: 3
Platform: Leetcode

```cpp
class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> res;
        int n = nums.size();
        for(int i = 0; i < 2 * (n); i++) {
            res.emplace_back(nums[i % n]);
        }
        return res;
    }
};
```