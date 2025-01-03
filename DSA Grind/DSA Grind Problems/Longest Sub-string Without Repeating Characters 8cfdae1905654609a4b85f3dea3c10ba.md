# Longest Sub-string Without Repeating Characters

Tags: Sliding Window, string
Level: Medium
Number: 16
Platform: Leetcode
URL: https://leetcode.com/problems/longest-substring-without-repeating-characters/

Given a string `s`, find the length of the **longest**

**sub-string**

without repeating characters.

**Example 1:**

```
Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.

```

**Example 2:**

```
Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.

```

**Example 3:**

```
Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.

```

**Constraints:**

- `0 <= s.length <= 5 * 104`
- `s` consists of English letters, digits, symbols and spaces.

## Solution

1. We improve upon the first solution by using an unordered map (`charMap`) instead of a set.
2. The map stores characters as keys and their indices as values.
3. We still maintain the `left` and `right` pointers and the `maxLength` variable.
4. We iterate through the string using the `right` pointer.
5. If the current character is not in the map or its index is less than `left`, it means it is a new unique character.6 We update the `charMap` with the character's index and update the `maxLength` if necessary.
6. If the character is repeating within the current substring, we move the `left` pointer to the next position after the last occurrence of the character.
7. We update the index of the current character in the `charMap` and continue the iteration.
8. At the end, we return the `maxLength` as the length of the longest substring without repeating characters.

```cpp
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() == 0) return 0;
        unordered_map<char, int> m;
        int max_res = 0;
        int start = 0;
        int cur = 0;
        while(cur < s.size()) {
            if(m.find(s[cur]) == m.end() || m[s[cur]] < start) {
                m[s[cur]] = cur;
                max_res = max(max_res, cur - start + 1);
            } else {
                start = m[s[cur]] + 1;
                m[s[cur]] = cur;
            }
            cur++;
        }
        
        return max_res;
    }
};
```

[Kadane’s Algorithm : Maximum Subarray Sum in an Array](https://takeuforward.org/data-structure/kadanes-algorithm-maximum-subarray-sum-in-an-array/)