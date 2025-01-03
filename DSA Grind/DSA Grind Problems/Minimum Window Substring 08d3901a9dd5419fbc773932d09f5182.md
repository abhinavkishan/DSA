# Minimum Window Substring

Tags: Hash Table, Sliding Window, string
Date: August 17, 2023
Level: Hard
Number: 19
Platform: Leetcode

- Here we’re storing all the characters from string t to an unordered_map ***mp***.
- We are taking 3 variables, ans(to store the size of the minimum substring), start(to store the start index) & count(to store the map size, if it became 0 that means we got a substring)
- Now taking 2 pointers i & j, we’ll iterate using j & will decrement the element count in map.
- if at any point the value became 0 that means we got all the elements of that char till now, so we’ll decrement the size of the count.
- In this way, we will decrement and once the count will be 0 if there is a substring with all the elements present.
- Now we’ll increment i and check if there is possible to remove any more characters and get smaller substrings.
- We’ll store the smaller length to ans & store the ith index in the start variable. Also, we’ll add the element to our map and increment the count variable if it became greater than 0.
- Now if the ans have some length except int_max, then return the substring from start index to length of ans. Else return empty string.
- **Time complexity:** O(m), where m is the length of string s.

```cpp
class Solution {
public:
    string minWindow(string s, string t) {
        int m = t.size(), n = s.size();
        string res;
        if(m == 0 || n == 0 || m > n) return res;
        int minLen = INT_MAX;
        int minStart = 0;
        unordered_map<char, int> map;
        for(char x: t) {
            map[x]++;
        } 
        int count = map.size();
        int i = 0, j = 0;
        while(j < n) {
            map[s[j]]--;
            if(map[s[j]] == 0) count--;
            if(count == 0) {
                while(count == 0) {
                    if(minLen > (j - i + 1)) {
                        minLen = j - i + 1;
                        minStart = i;
                    }
                    map[s[i]]++;
                    if(map[s[i]] > 0) count++;
                    i++;
                }
            }
            j++;
        }
        return minLen == INT_MAX ? "" : s.substr(minStart, minLen);
    }
};
```

```cpp
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> map;
        for(auto x: s1) {
            map[x]++;
        }
        int count = map.size();
        int i = 0, j = 0;
        int n = s2.size();
        while(j < n) {
            if(map.count(s2[j])) {
                i = j;
                while(j < n && count) {
                    if(!map.count(s2[j])) {
                        break;
                    }
                    map[s2[j]]--;
                    if(map[s2[j]] == 0) count--;
                    j++;
                }
                if(count == 0 && (j - i) == s1.size()) return true;
                if(j < n) {
                    while(i < j) {
                        if(map[s2[i]] == 0) count++;
                        map[s2[i]]++;
                        i++;
                    }
                }
            }
            j++;
        }
        return false;
    }
};
```