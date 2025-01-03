class Solution {
public:
    string minWindow(string s, string t) {
        int m = t.size(), n = s.size();
        string res;
        if(m == 0 || n == 0 || m > n) return res;
        int minLen = INT_MAX;
        int minStart = 0;
        unordered_map<char, int> map;
        for(char x: t) {
            map[x]++;
        } 
        int count = map.size();
        int i = 0, j = 0;
        while(j < n) {
            map[s[j]]--;
            if(map[s[j]] == 0) count--;
            if(count == 0) {
                while(count == 0) {
                    if(minLen > (j - i + 1)) {
                        minLen = j - i + 1;
                        minStart = i;
                    }
                    map[s[i]]++;
                    if(map[s[i]] > 0) count++;
                    i++;
                }
            }
            j++;
        }
        return minLen == INT_MAX ? "" : s.substr(minStart, minLen);
    }
};
