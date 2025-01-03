class Solution {
public:
    bool isSubsequence(string s, string t) {
        int p1 = 0;
        int p2 = 0;
        int n = t.size();
        while(p1 < n){
            if(s[p2] == t[p1]) p2++;
            p1++;
        }
        return p2 == s.size() ? true : false;
    }
};
