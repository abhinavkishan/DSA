# Determine the Minimum Sum of a k-avoiding Array

Tags: Arrays, Hash Table
Date: August 20, 2023
Level: Medium
Number: 21
Platform: Leetcode

# Intuition

The intuition behind the solution is to use a greedy approach. The 
algorithm starts with the smallest integer and adds it to the sum. Then,
 it adds the next integer that is at most k away from the previous 
integer. The algorithm repeats this process until the sum reaches n.

# Approach

The approach is to create a hash map to store the frequencies of the 
integers that have been added to the sum. The algorithm then iterates 
through the integers from 1 to n. For each integer, the algorithm checks
 if the integer is at most k away from the previous integer. If it is, 
the algorithm adds the integer to the sum and increments the frequency 
of the integer in the hash map.

The algorithm returns the sum.

# Complexity

- Time complexity:

O(n) - We iterate through n elements to construct the k-avoiding array.

- Space complexity:

O(k) - The space used by the hash map to store elements.

```cpp
class Solution {
public:
    int minimumSum(int n, int k) {
        unordered_set<int> s;
        int i = 0, start = 1, minSum = 0;
        while(i < n) {
            int diff = k - start;
            if(s.find(diff) == s.end()) {
                minSum += start;
                s.insert(start);
                start++, i++;
            } else {
                start++;
            }
        }
        return minSum;
    }
};
```