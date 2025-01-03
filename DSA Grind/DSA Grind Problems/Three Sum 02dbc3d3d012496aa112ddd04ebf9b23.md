# Three Sum

Tags: Arrays, Two Pointers
Level: Medium
Number: 15
Platform: Leetcode

```cpp
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> out;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++) {
            int num = - nums[i];
            if((i > 0) && nums[i - 1] == - num) continue;
            int start = i+1;
            int end = nums.size() - 1;
            while(start < end) {
                int sum = nums[start] + nums[end];
                if(sum == num) {
                    out.push_back({nums[i], nums[start], nums[end]});
                    while((start + 1 < end) && nums[start + 1] == nums[start]) start++;
                    while((start < end - 1) && nums[end - 1] == nums[end]) end--;
                    start++, end--;
                } else if(sum < num) {
                    start++;
                } else {
                    end--;
                }
            }
        }
        
        return out;
    }
};
```