# Subset Sums

Tags: Recursion
Date: October 24, 2023
Level: Medium
Number: 44
Platform: GFG
URL: https://practice.geeksforgeeks.org/problems/subset-sums2234/1

Given a list **arr** of **N** integers, return sums of all subsets in it.

**Example 1:**

```
Input:
N = 2
arr[] = {2, 3}
Output:
0 2 3 5
Explanation:
When no elements is taken then Sum = 0.
When only 2 is taken then Sum = 2.
When only 3 is taken then Sum = 3.
When element 2 and 3 are taken then
Sum = 2+3 = 5.
```

**Example 2:**

```
Input:
N = 3
arr = {5, 2, 1}
Output:
0 1 2 3 5 6 7 8

```

**Your Task:**  You don't need to read input or print anything. Your task is to complete the function **subsetSums**() which takes a list/vector and an integer **N** as an input parameter and return the list/vector of all the subset sums.

**Expected Time Complexity:** O(2N)**Expected Auxiliary Space:** O(2N)

**Constraints:**1 <= N <= 150 <= arr[i] <= 104

## Solution

[Subset Sum : Sum of all Subsets - Recursion](https://takeuforward.org/data-structure/subset-sum-sum-of-all-subsets/)

```cpp
class Solution {
  public:
    void subsetSumsHelper(int ind, vector < int > & arr, int n, vector < int > & ans, int sum) {
      if (ind == n) {
        ans.push_back(sum);
        return;
      }
      subsetSumsHelper(ind + 1, arr, n, ans, sum);
      //element is picked
      subsetSumsHelper(ind + 1, arr, n, ans, sum + arr[ind]);
      //element is not picked
      
    }
  vector < int > subsetSums(vector < int > arr, int n) {
    vector < int > ans;
    subsetSumsHelper(0, arr, n, ans, 0);
    // sort(ans.begin(), ans.end());
    return ans;
  }
};
```