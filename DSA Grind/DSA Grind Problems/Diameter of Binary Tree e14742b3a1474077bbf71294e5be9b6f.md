# Diameter of Binary Tree

Tags: Binary Tree, DFS, Tree
Date: October 16, 2023
Level: Easy
Number: 42
Platform: Leetcode
URL: https://leetcode.com/problems/diameter-of-binary-tree/description/

Given the `root` of a binary tree, return *the length of the **diameter** of the tree*.

The **diameter** of a binary tree is the **length** of the longest path between any two nodes in a tree. This path may or may not pass through the `root`.

The **length** of a path between two nodes is represented by the number of edges between them.

**Example 1:**

![https://assets.leetcode.com/uploads/2021/03/06/diamtree.jpg](https://assets.leetcode.com/uploads/2021/03/06/diamtree.jpg)

```
Input: root = [1,2,3,4,5]
Output: 3
Explanation: 3 is the length of the path [4,2,1,3] or [5,2,1,3].

```

**Example 2:**

```
Input: root = [1,2]
Output: 1

```

**Constraints:**

- The number of nodes in the tree is in the range `[1, 104]`.
- `100 <= Node.val <= 100`

## Solution

```cpp
class Solution {
private:
    int findDiameter(TreeNode *root, int& diameter) {
        if(!root) return 0;
        int lh = findDiameter(root->left, diameter);
        int rh = findDiameter(root->right, diameter);
        diameter = max(diameter, lh + rh);
        return 1 + max(lh, rh);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        findDiameter(root, diameter);
        return diameter;
    }
};
```

[https://youtu.be/Rezetez59Nk?si=pPiqktcAMxOMTbYi](https://youtu.be/Rezetez59Nk?si=pPiqktcAMxOMTbYi)