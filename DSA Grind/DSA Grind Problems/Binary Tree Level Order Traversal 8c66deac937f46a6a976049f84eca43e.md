# Binary Tree Level Order Traversal

Tags: BFS, Binary Tree, Tree
Date: October 25, 2023
Level: Medium
Number: 45
Platform: Leetcode
URL: https://leetcode.com/problems/binary-tree-level-order-traversal/

Given the `root` of a binary tree, return *the level order traversal of its nodes' values*. (i.e., from left to right, level by level).

**Example 1:**

![https://assets.leetcode.com/uploads/2021/02/19/tree1.jpg](https://assets.leetcode.com/uploads/2021/02/19/tree1.jpg)

```
Input: root = [3,9,20,null,null,15,7]
Output: [[3],[9,20],[15,7]]

```

**Example 2:**

```
Input: root = [1]
Output: [[1]]

```

**Example 3:**

```
Input: root = []
Output: []

```

**Constraints:**

- The number of nodes in the tree is in the range `[0, 2000]`.
- `1000 <= Node.val <= 1000`

## Solution

[https://www.youtube.com/watch?v=6ZnyEApgFYg](https://www.youtube.com/watch?v=6ZnyEApgFYg)

```cpp
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> nodes;
        vector<vector<int>> res;
        if(!root) return res;
        vector<int>val;
        nodes.push(root);
        nodes.push(NULL);
        while(!nodes.empty()) {
            TreeNode *cur = nodes.front();
            nodes.pop();
            if(!cur) {
                res.push_back(val);
                val.resize(0);
                if(!nodes.empty()) nodes.push(NULL);
            } else {
                val.push_back(cur->val);
                if(cur->left) nodes.push(cur->left);
                if(cur->right) nodes.push(cur->right);
            }
        }
        return res;
    }
};
```

<aside>
💡 The biggest level of a binary tree can have maximum N/2 elements

</aside>