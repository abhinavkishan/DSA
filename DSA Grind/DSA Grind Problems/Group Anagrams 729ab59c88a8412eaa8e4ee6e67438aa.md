# Group Anagrams

Tags: Arrays
Level: Medium
Number: 6
Platform: Leetcode

```cpp
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> hash;
        for(string x: strs) {
            string t = x;
            sort(t.begin(), t.end());
            hash[t].emplace_back(x);
        }
        vector<vector<string>> res;
        for(pair<string, vector<string>> x: hash) {
            res.emplace_back(x.second);
        }
        return res;
    }
};
```