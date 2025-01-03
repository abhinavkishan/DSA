# Contains Duplicate

Tags: Arrays, Hash Table, Sorting
Level: Easy
Number: 1
Platform: Leetcode

```cpp
unordered_map<long,long> map;   
        for(int i=0; i<nums.size(); i++){
            map[nums[i]]++;
        }
        for(int i=0; i<nums.size(); i++){
            if(map[nums[i]] > 1){
                return true;
            }
        }
        return false;
```

```cpp
set<int> s(nums.begin(), nums.end());
return nums.size() > s.size() ? true : false;
```

```cpp
bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> hash;
        for(auto x: nums) {
            hash[x]++;
            if(hash[x] > 1) return true;
        }
        return false;
    }
```