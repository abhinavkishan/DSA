# Longest Consecutive Sequence

Tags: Arrays, Hash Table
Date: August 9, 2023
Level: Medium
Number: 11
Platform: Leetcode
URL: https://leetcode.com/problems/longest-consecutive-sequence/description/

Given an unsorted array of integers `nums`, return *the length of the longest consecutive elements sequence.*

You must write an algorithm that runs in `O(n)` time.

**Example 1:**

```
Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is[1, 2, 3, 4]. Therefore its length is 4.

```

**Example 2:**

```
Input: nums = [0,3,7,2,5,8,4,6,0,1]
Output: 9

```

**Constraints:**

- `0 <= nums.length <= 105`
- `109 <= nums[i] <= 10`

## Solution

[https://www.youtube.com/watch?v=P6RZZMu_maU](https://www.youtube.com/watch?v=P6RZZMu_maU)

```cpp
/*

    Time Complexity : O(N), Although the time complexity appears to be quadratic due to the while loop nested
    within the for loop, closer inspection reveals it to be linear. Because the while loop is reached only when
    marks the beginning of a sequence (i.e. currentNumber-1 is not present in nums), the while loop can only run
    for N iterations throughout the entire runtime of the algorithm. This means that despite looking like O(N^2)
    complexity, the nested loops actually run in O(N+N)=O(N) time. All other computations occur in constant
    time, so the overall runtime is linear. Where N is the size of the Array(nums).

    Space Complexity : O(N), Unordered set space.

    Solved using Array + Hash Table(Unordered set). Optimise Approach.

*/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set;
        for(int num : nums){
            set.insert(num);
        }
        int longestConsecutiveSequence = 0;
        for(int num : nums){
						// searching for a  start value (has no left neighnour)
            if(set.find(num-1) == set.end()){
                int currentNumber = num;
                int currentConsecutiveSequence = 1;
                while(set.find(currentNumber+1) != set.end()){
                    currentNumber++;
                    currentConsecutiveSequence++;
                }
                longestConsecutiveSequence = max(longestConsecutiveSequence, currentConsecutiveSequence);
            }
        }
        return longestConsecutiveSequence;
    }
};
```