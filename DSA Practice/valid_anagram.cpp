class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;

        unordered_map<char, int> hm;
        for(auto x: s) {
            hm[x]++;
        }
        
        for(auto x: t) {
            hm[x]--;
        }
        
        for(auto x: hm) {
            if(x.second != 0) return false;
        }
        return true;
    }
};
