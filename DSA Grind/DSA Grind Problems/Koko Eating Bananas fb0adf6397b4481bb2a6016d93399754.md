# Koko Eating Bananas

Tags: Arrays, Binary Search
Date: August 27, 2023
Level: Revisit
Number: 25
Platform: Leetcode

# **Intuition**

We need to find the minimum integer `k` such that Koko can eat all the bananas within `h`

hours. This means that we need to find the smallest value of `k` such that she can eat all

the bananas within `h` hours.

# **Approach**

1. Initialize left and right pointers as `left = 1` and `right = maximum number of bananas in any pile`.
2. While the left pointer is less than the right pointer, repeat the following:a. Calculate the middle pointer using `mid = (left + right) / 2`.b. Check if Koko can eat all the bananas at the current speed (middle pointer) within `h` hours using the `canEatAll` method.c. If Koko can eat all the bananas at the current speed, update the right pointer to the middle pointer using `right = mid`.d. If Koko cannot eat all the bananas at the current speed, update the left pointer to `mid + 1`.
3. Once the left pointer is equal to the right pointer, return the left pointer as the minimum speed at which Koko can eat all the bananas within h hours.The `canEatAll` method calculates the total time required to eat all the piles using the given speed. If the total time is greater than h, the method returns `false`, otherwise, itreturns `true`.

# **Complexity**

- Time complexity:

The binary search algorithm has a time complexity of O(logn), where n is the maximum number of bananas in a pile. The canEatAll function has a time complexity of O(n), where n is the number of piles. Therefore, the overall time complexity of the solution is O(nlogn).

- Space complexity:The space complexity of the solution is O(1), as we only use a constant amount of extra space.

```cpp
class Solution {
public:
    int eatingTime(vector<int>& piles, int k) {
        long long time = 0;
        for(int x: piles) {
            time += ceil(x / (double) k);
        }
        return time;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int i = 1, j = *max_element(piles.begin(), piles.end());
        long long time_taken;
        while(i < j) {
            int mid = i + (j - i) / 2;
            time_taken = eatingTime(piles, mid);
            if(time_taken <= h) {
                // reduce speed
                j = mid;
            } else {
                // increase speed
                i = mid + 1;
            }
        }
        return i;
    }
};
```