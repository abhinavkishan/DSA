# valid anagram

Tags: Hash Table, Sorting, string
Level: Easy
Number: 2
Platform: Leetcode

```cpp
class Solution {
public:
    bool isAnagram(string s, string t) {
		  sort(s.begin(), s.end())
			sort(t.begin(), t.end())
			return s == t;
    }
};
```

```cpp
class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> hashmap;
        for(auto x: s) {
            hashmap[x]++;
        }
    
        for(auto x: t) {
            hashmap[x]--;
        }
				
				for(auto x: hashmap) {
						if(x.second != 0) return false;
				}
        return true;
    }
};

```