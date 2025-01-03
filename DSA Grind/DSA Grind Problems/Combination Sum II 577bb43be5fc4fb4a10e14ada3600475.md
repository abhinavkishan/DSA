# Combination Sum II

Tags: Arrays, Backtracking
Date: November 4, 2023
Level: Medium
Number: 48
Platform: Leetcode
URL: https://leetcode.com/problems/combination-sum-ii/

Given a collection of candidate numbers (`candidates`) and a target number (`target`), find all unique combinations in `candidates` where the candidate numbers sum to `target`.

Each number in `candidates` may only be used **once** in the combination.

**Note:** The solution set must not contain duplicate combinations.

**Example 1:**

```
Input: candidates = [10,1,2,7,6,1,5], target = 8
Output:
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]

```

**Example 2:**

```
Input: candidates = [2,5,2,1,2], target = 5
Output:
[
[1,2,2],
[5]
]

```

**Constraints:**

- `1 <= candidates.length <= 100`
- `1 <= candidates[i] <= 50`
- `1 <= target <= 30`

## Solution

```cpp
class Solution {
public:
    void helper(int idx, vector<int>&ds, vector<int>&nums, int target, vector<vector<int>>&res) {
        if(target == 0) {
            res.push_back(ds);
        }
        for(int i = idx; i < nums.size(); i++) {
            if(i > idx && nums[i] == nums[i - 1]) continue;
            if(nums[i] > target) return;
            ds.push_back(nums[i]);
            helper(i+1, ds, nums, target - nums[i], res);
            ds.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> ds;
        vector<vector<int>> res;
        sort(candidates.begin(), candidates.end());
        helper(0, ds, candidates, target, res);
        return res;
    }
};
```

[Combination Sum II – Find all unique combinations - Updated](https://takeuforward.org/data-structure/combination-sum-ii-find-all-unique-combinations/)

This problem asks you to find all unique combinations of numbers in the given `candidates` array that sum up to the `target`, and each number in the combination can be used only once. The algorithm avoids duplicate combinations.

Now, let's analyze the time complexity of this algorithm:

1. Sorting:
Before starting the backtracking process, the code sorts the `candidates` array using `std::sort`. The time complexity of this sorting operation is O(n * log(n)), where n is the number of elements in the `candidates` array.
2. Backtracking:
The core of the algorithm is the `findCombination` function, which performs the backtracking search. It iterates through the elements of the `candidates` array and explores all possible combinations. The time complexity of the backtracking portion can be analyzed as follows:
    - The function is called for each element in the `candidates` array, so in the worst case, it is called for all elements. This contributes O(n) to the time complexity.
    - Within the backtracking function, there's a loop that iterates from `ind` to `arr.size()`. In the worst case, this loop may iterate over all elements. In the average case, the number of iterations is smaller due to pruning (skipping duplicates and breaking early if `arr[i]` is greater than `target`).
    - For each call to the `findCombination` function, there are two recursive calls, one with `i + 1` and one with `i`. The total number of recursive calls is proportional to the number of nodes in the recursion tree, which is related to the number of possible combinations.
    
    Due to the backtracking and pruning, the actual number of recursive calls is significantly smaller than the total number of combinations. However, the worst-case time complexity for the backtracking part is still exponential, O(2^n), where n is the number of elements in the `candidates` array. This is because, in the worst case, you might have to explore all possible combinations.
    
3. Asymptotic Complexity:
Combining the time complexities of sorting and backtracking, the overall time complexity of the `combinationSum2` function is O(n * log(n) + 2^n), where n is the number of elements in the `candidates` array.

In practice, the algorithm often performs better than the worst case because of the pruning conditions that skip over some combinations. However, the worst-case time complexity is exponential due to the nature of the problem.