# Kth Smallest Element in a BST

Tags: Binary Search Tree, Binary Tree, DFS, Tree
Date: November 12, 2023
Level: Medium
Number: 53
Platform: Leetcode
URL: https://leetcode.com/problems/kth-smallest-element-in-a-bst/description/

Given the `root` of a binary search tree, and an integer `k`, return *the* `kth` *smallest value (**1-indexed**) of all the values of the nodes in the tree*.

**Example 1:**

![https://assets.leetcode.com/uploads/2021/01/28/kthtree1.jpg](https://assets.leetcode.com/uploads/2021/01/28/kthtree1.jpg)

```
Input: root = [3,1,4,null,2], k = 1
Output: 1

```

**Example 2:**

![https://assets.leetcode.com/uploads/2021/01/28/kthtree2.jpg](https://assets.leetcode.com/uploads/2021/01/28/kthtree2.jpg)

```
Input: root = [5,3,6,2,4,null,null,1], k = 3
Output: 3

```

**Constraints:**

- The number of nodes in the tree is `n`.
- `1 <= k <= n <= 104`
- `0 <= Node.val <= 104`

## Solution

[https://www.youtube.com/watch?v=9TJYWh0adfk](https://www.youtube.com/watch?v=9TJYWh0adfk)

```cpp
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> st;
        TreeNode* cur = root;
        while(!st.empty() || cur) {
            while (cur) {
                st.push(cur);
                cur = cur->left;
            }
            cur = st.top(); st.pop();
            k--;
            if(!k) return cur->val;
            cur = cur->right;
        }
        return INT_MIN;
    }
};
```

> For Kth largest, find N-k th smallest
>