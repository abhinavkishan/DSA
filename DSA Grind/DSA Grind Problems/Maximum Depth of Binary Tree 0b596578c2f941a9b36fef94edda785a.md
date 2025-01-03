# Maximum Depth of Binary Tree

Tags: BFS, Binary Tree, DFS, Tree
Date: October 9, 2023
Level: Easy
Number: 39
Platform: Leetcode
URL: https://leetcode.com/problems/maximum-depth-of-binary-tree/description/

Given the `root` of a binary tree, return *its maximum depth*.

A binary tree's **maximum depth** is the number of nodes along the longest path from the root node down to the farthest leaf node.

**Example 1:**

![Maximum%20Depth%20of%20Binary%20Tree%200b596578c2f941a9b36fef94edda785a/tmp-tree.jpg](Maximum%20Depth%20of%20Binary%20Tree%200b596578c2f941a9b36fef94edda785a/tmp-tree.jpg)

```
Input: root = [3,9,20,null,null,15,7]
Output: 3

```

**Example 2:**

```
Input: root = [1,null,2]
Output: 2

```

**Constraints:**

- The number of nodes in the tree is in the range `[0, 104]`.
- `100 <= Node.val <= 100`

Similar Questions

[Balanced Binary Tree](https://leetcode.com/problems/balanced-binary-tree/)

[Amount of Time for Binary Tree to Be Infected](https://leetcode.com/problems/amount-of-time-for-binary-tree-to-be-infected/)

## Solution

[https://www.youtube.com/watch?v=hTM3phVI6YQ](https://www.youtube.com/watch?v=hTM3phVI6YQ)

```cpp
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
};
```

```cpp
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        int level = 0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int n = q.size();
            for(int i = 0; i < n; i++) {
                TreeNode* node = q.front();
                q.pop();
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            level++;
        }
        return level;
    }
};
```

```cpp
class Solution {
public:
    int maxDepth(TreeNode* root) {
        //Preorder DFS
        
        stack<pair<TreeNode*,int>> s;
        s.push(make_pair(root, 1));
        int res = 0;

        while(!s.empty()) {
            auto x = s.top();
            s.pop();
            if(x.first) {
                res = max(res, x.second);
                s.push(make_pair(x.first->left, x.second+1));
                s.push(make_pair(x.first->right, x.second+1));
            }
        }   
        return res;
    }
};
```