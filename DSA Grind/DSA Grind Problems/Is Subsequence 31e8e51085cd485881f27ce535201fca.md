# Is Subsequence

Tags: Arrays
Level: Easy
Number: 4
Platform: Leetcode
URL: https://leetcode.com/problems/is-subsequence/description/

Given two strings `s` and `t`, return `true` *if  is a **subsequence** of , or* `false` *otherwise*.

A **subsequence** of a string is a new string that is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (i.e., `"ace"` is a subsequence of `"abcde` while `"aec"` is not).

**Example 1:**

```
Input: s = "abc", t = "ahbgdc"
Output: true

```

**Example 2:**

```
Input: s = "axc", t = "ahbgdc"
Output: false

```

**Constraints:**

- `0 <= s.length <= 100`
- `0 <= t.length <= 104`
- `s` and `t` consist only of lowercase English letters.

**Follow up:** Suppose there are lots of incoming `s`, say `s1, s2, ..., sk` where `k >= 109`, and you want to check one by one to see if `t` has its subsequence. In this scenario, how would you change your code?

```cpp
//  USING DYNAMIC PROGRAMMING 
// if LCS of string A  nd B is equal to Size of String A then its True else false;

class Solution {
public:
    int helper(string x, string y) {
        int m = x.size();
        int n = y.size();
        int dp[m+1][n+1];
        for(int i = 0; i<=m; i++)
        {
            dp[i][0]=0;
        }
        for(int i = 0; i<=n; i++)
        {
            dp[0][i]=0;
        }
        for(int i = 1; i<=m; i++){
            for(int j = 1; j<=n; j++){
                if(x[i-1]==y[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[m][n];
    }
    bool isSubsequence(string smaller, string larger) {

        int x  = helper(smaller,larger);
        if(x == smaller.size()){
            return true;
        }
        return false;      
    }
};
```

```cpp
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int p1 = 0;
        int p2 = 0;
        int n = t.size();
        while(p1 < n){
            if(s[p2] == t[p1]) p2++;
            p1++;
        }
        return p2 == s.size() ? true : false;
    }
};
```