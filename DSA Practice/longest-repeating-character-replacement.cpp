class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        if(n == 0) return 0;
        unordered_map<char, int> m;
        int i = 0;
        int j = 0;
        int max_res = 0;
        int maxCount = 0;
        while(j < n) {
            m[s[j]]++;
            maxCount = max(maxCount, m[s[j]]);
            int len = j - i + 1;
            if(len - maxCount > k) {
                m[s[i]]--;
                i++;
            }
            max_res = max(max_res, j - i + 1);
            j++;
        }
        return max_res;
    }
};
