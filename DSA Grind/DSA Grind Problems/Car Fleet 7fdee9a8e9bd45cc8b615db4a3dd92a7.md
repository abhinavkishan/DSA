# Car Fleet

Tags: Stack
Date: August 19, 2023
Level: Medium
Number: 20
Platform: Leetcode

# **Intuition**

The given problem is quite similar to the real world Traffic Jams, where a car's path is indirectly controlled by the car in front, we somehow try to achieve the above through a monotonic stack.

# **Approach**

A fleet of size > 1 is formed if a car is slower than the car behind it and there is enough time for the car behind to catch the car in front before reaching the target destination.

- As you can see, the leading factor here is time.
- lets assume a simple case scenario of 3 cars - A, B, C at position 0, 1, 2 respectively having speed 50, 20, 30 respectively.
- Lets assume the target is 50
- Time taken by A = (50-0)/50 = 1
- Time taken by B = (50-1)/20 = 2.45
- Time taken by C = (50-2)/30 = 1.6

Car C being closest to target with no car in front will take 1.6 time, Car B takes greater time than Car C as expected, hence it wont be able to catch car C. Car A on the other hand takes the miniumum time but ahead lies much slower car B and it is hindered and forced to move with car B forming a fleet

Below is the C++ implementation using stack of the above explanation

```cpp
class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> vehicles;
        for(int i = 0; i < position.size(); i++) {
            vehicles.emplace_back(make_pair(position[i],speed[i]));
        }   
        sort(vehicles.begin(), vehicles.end());
        stack<double> st;
        for(int i = vehicles.size() - 1; i >= 0; i--) {
            double t = (target - vehicles[i].first) / (double) vehicles[i].second;
            if(st.empty() || st.top() < t) {
                st.push(t);
            }
        }

        return st.size();

    }
};
```