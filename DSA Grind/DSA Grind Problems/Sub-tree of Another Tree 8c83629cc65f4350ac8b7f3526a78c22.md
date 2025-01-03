# Sub-tree of Another Tree

Tags: DFS, Hash Table, Tree
Date: October 11, 2023
Level: Easy
Number: 40
Platform: Leetcode
URL: https://leetcode.com/problems/subtree-of-another-tree/description/

Given the roots of two binary trees `root` and `subRoot`, return `true` if there is a subtree of `root` with the same structure and node values of `subRoot` and `false` otherwise.

A subtree of a binary tree `tree` is a tree that consists of a node in `tree` and all of this node's descendants. The tree `tree` could also be considered as a subtree of itself.

**Example 1:**

![Sub-tree%20of%20Another%20Tree%208c83629cc65f4350ac8b7f3526a78c22/subtree1-tree.jpg](Sub-tree%20of%20Another%20Tree%208c83629cc65f4350ac8b7f3526a78c22/subtree1-tree.jpg)

```
Input: root = [3,4,5,1,2], subRoot = [4,1,2]
Output: true

```

**Example 2:**

![Sub-tree%20of%20Another%20Tree%208c83629cc65f4350ac8b7f3526a78c22/subtree2-tree.jpg](Sub-tree%20of%20Another%20Tree%208c83629cc65f4350ac8b7f3526a78c22/subtree2-tree.jpg)

```
Input: root = [3,4,5,1,2,null,null,null,null,0], subRoot = [4,1,2]
Output: false

```

**Constraints:**

- The number of nodes in the `root` tree is in the range `[1, 2000]`.
- The number of nodes in the `subRoot` tree is in the range `[1, 1000]`.
- `104 <= root.val <= 104`
- `104 <= subRoot.val <= 104`

## Solution

[https://www.youtube.com/watch?v=E36O5SWp-LE](https://www.youtube.com/watch?v=E36O5SWp-LE)

```cpp
class Solution {
public:
   
   bool isSametree(TreeNode* s, TreeNode* t){
       //if any of the tree is null then there is no need to compare 
       if(!s || !t){
           //if either of them are null both of them need to be null to be true
           return s==NULL && t==NULL;
       } //now since both are not null check if they have same value otherwise return false
       else if(s->val == t->val){
           //if value is same then check if both its left and right sub-tree are same          
           return isSametree(s->left,t->left) && isSametree(s->right,t->right);
       }
       else{
           return false;
       }
   }
   bool isSubtree(TreeNode* s, TreeNode* t) {
         if(!s){
             //if main tree is null then return false
             return false;
         }   
         else if(isSametree(s,t)){
             //check if s and t are same, if yes return true
             return true;
         }
         else{
             //if s and t are not same then pass left and right nodes, and check same for that nodes as well as its child nodes.
             return isSubtree(s->left,t) || isSubtree(s->right,t);
         }
   }
};
```