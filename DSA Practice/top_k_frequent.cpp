class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> hm;
        for(int x: nums) {
            hm[x]++;
        }
        vector<int> res;
        vector<vector<int>> buckets(nums.size()+1);
        for(auto x: hm) {
            buckets[x.second].push_back(x.first);
        }
        for(int i = buckets.size() - 1; i >= 0 && res.size() < k; i--) {
            for(int x: buckets[i]) {
                res.emplace_back(x);
                if(res.size() == k) break;
            }
        }
        return res;
    }
};
