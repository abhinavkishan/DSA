# Permutatuions II

Tags: Arrays, Backtracking
Date: November 12, 2023
Level: Revisit
Number: 52
Platform: Leetcode
URL: https://leetcode.com/problems/permutations-ii/description/

Given a collection of numbers, `nums`, that might contain duplicates, return *all possible unique permutations **in any order**.*

**Example 1:**

```
Input: nums = [1,1,2]
Output:
[[1,1,2],
 [1,2,1],
 [2,1,1]]

```

**Example 2:**

```
Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

```

**Constraints:**

- `1 <= nums.length <= 8`
- `10 <= nums[i] <= 10`

## Solution

[https://www.youtube.com/watch?v=qhBVWf0YafA](https://www.youtube.com/watch?v=qhBVWf0YafA)

```cpp
class Solution {
public:
    void recurPermute(int idx,vector<int>& ds, unordered_map<int, int>& hm, int n, vector<vector<int>>& res) {
        if(idx == n) {
            res.push_back(ds);
            return;
        }
        
        for(auto [key, value]: hm) {
            if(value > 0) {
                hm[key]--;
                ds.push_back(key);
                recurPermute(idx+1, ds, hm, n, res);
                ds.pop_back();
                hm[key]++;
            }
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> ds;
        unordered_map<int, int> hm;
        for(auto x: nums) {
            hm[x]++;
        }
        recurPermute(0, ds, hm, nums.size(),res);
        return res;
    }
};
```