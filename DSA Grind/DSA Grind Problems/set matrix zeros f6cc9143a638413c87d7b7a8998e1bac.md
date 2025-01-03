# set matrix zeros

Tags: Arrays
Level: Medium
Number: 8
Platform: Leetcode
URL: https://leetcode.com/problems/set-matrix-zeroes/description/

Given an `m x n` integer matrix `matrix`, if an element is `0`, set its entire row and column to 's.

You must do it [in place](https://en.wikipedia.org/wiki/In-place_algorithm).

**Example 1:**

![set%20matrix%20zeros%20f6cc9143a638413c87d7b7a8998e1bac/mat1.jpg](set%20matrix%20zeros%20f6cc9143a638413c87d7b7a8998e1bac/mat1.jpg)

```
Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
Output: [[1,0,1],[0,0,0],[1,0,1]]

```

**Example 2:**

![set%20matrix%20zeros%20f6cc9143a638413c87d7b7a8998e1bac/mat2.jpg](set%20matrix%20zeros%20f6cc9143a638413c87d7b7a8998e1bac/mat2.jpg)

```
Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]

```

**Constraints:**

- `m == matrix.length`
- `n == matrix[0].length`
- `1 <= m, n <= 200`
- `231 <= matrix[i][j] <= 2 - 1`

**Follow up:**

- A straightforward solution using `O(mn)` space is probably a bad idea.
- A simple improvement uses `O(m + n)` space, but still not the best solution.
- Could you devise a constant space solution?

## Solution

[Set Matrix Zero - Leetcode - Tutorial](https://takeuforward.org/data-structure/set-matrix-zero/)

```cpp
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix[0].size();
        int n = matrix.size();
        int col0 = 1;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(matrix[i][j] == 0) {
                    // marking row
                    matrix[i][0] = 0;
                    // marling column;
                    if(j == 0) col0 = 0;
                    else matrix[0][j] = 0;
                }
            }
        }

        for(int i = 1; i < n;i++) {
            for(int j = 1; j < m; j++) {
                if(matrix[i][j]) {
                    if(matrix[0][j] == 0 || matrix[i][0] == 0) matrix[i][j] = 0;
                }
            }
        }

        if(matrix[0][0] == 0) {
            for(int j = 0; j < m; j++) matrix[0][j] = 0;
        }

        if(col0 == 0) {
            for(int i = 0; i < n; i++) matrix[i][0] = 0;
        }
    }
};
```