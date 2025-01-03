# Binary Tree Zigzag Level Order Traversal

Tags: BFS, Binary Tree, Tree
Date: November 4, 2023
Level: Medium
Number: 49
Platform: Leetcode
URL: https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/

Given the `root` of a binary tree, return *the zigzag level order traversal of its nodes' values*. (i.e., from left to right, then right to left for the next level and alternate between).

**Example 1:**

![https://assets.leetcode.com/uploads/2021/02/19/tree1.jpg](https://assets.leetcode.com/uploads/2021/02/19/tree1.jpg)

```
Input: root = [3,9,20,null,null,15,7]
Output: [[3],[20,9],[15,7]]

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
- `100 <= Node.val <= 100`

## Solution

```cpp
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*> levels;
        vector<vector<int>> res;
        if(!root) return res;
        bool rev = false;
        levels.push(root);

        while(!levels.empty()) {
            int n = levels.size();
            vector<int> temp(n);
            for(int i = 0; i < n; i++) {
                TreeNode* cur = levels.front();
                levels.pop();
                if(rev) {
                    temp[n - 1 - i] = cur->val;
                } else {
                    temp[i] = cur->val;
                }

                if(cur->left) levels.push(cur->left);
                if(cur->right) levels.push(cur->right);
            }
            res.push_back(temp);
            rev = !rev;
        }

        return res;
    }
};
```

[https://youtu.be/3OXWEdlIGl4?si=bvciMQyp3v2TDYkZ](https://youtu.be/3OXWEdlIGl4?si=bvciMQyp3v2TDYkZ)