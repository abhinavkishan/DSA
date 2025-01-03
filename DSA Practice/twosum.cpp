class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> nums2 = nums;
        sort(nums2.begin(), nums2.end());
        int x = 0, y = nums2.size() - 1, sum = 0;
        vector<int>res;
        while(x < y) {
            sum = nums2[x] + nums2[y];
            if(sum == target) {
                res.push_back(nums2[x]);
                res.push_back(nums2[y]);
                break;
            } else if(sum < target) x++;
            else y--;
        }
        vector<int> indices;
        for(x = 0; x < nums.size(); x++) {
            if(nums[x] == res[0] || nums[x] == res[1]) indices.push_back(x);
        }
        return indices;
    }
};
