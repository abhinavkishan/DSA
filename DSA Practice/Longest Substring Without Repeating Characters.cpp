class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() == 0) return 0;
        unordered_map<char, int> m;
        int max_res = 0;
        int start = 0;
        int cur = 0;
        while(cur < s.size()) {
            if(m.find(s[cur]) == m.end() || m[s[cur]] < start) {
                m[s[cur]] = cur;
                max_res = max(max_res, cur - start + 1);
            } else {
                start = m[s[cur]] + 1;
                m[s[cur]] = cur;
            }
            cur++;
        }
        
        return max_res;
    }
};
