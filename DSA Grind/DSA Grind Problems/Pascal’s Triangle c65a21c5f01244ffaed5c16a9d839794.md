# Pascal’s Triangle

Tags: Arrays, Dynamic Programming
Level: Easy
Number: 7
Platform: Leetcode

```cpp
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res(numRows);
        for(int i = 0; i < numRows; i++) {
            res[i].resize(i+1, 1);
            for(int j = 1; j < i; j++) {
                res[i][j] = res[i-1][j-1] + res[i-1][j];
            }
        }
        return res;
    }
};
```