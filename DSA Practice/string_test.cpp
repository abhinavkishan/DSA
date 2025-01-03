#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /*
     * @param strs: a list of strings
     * @return: encodes a list of strings to a single string.
     */
    string encode(vector<string> &strs) {
        stringstream s;
        for(int i = 0; i < strs.size() - 1; i++) {
            s << strs[i] << ";";
        }
        s << strs[strs.size() - 1];
        return s.str();
    }

    /*
     * @param str: A string
     * @return: decodes a single string to a list of strings
     */
    vector<string> decode(string &str) {
        stringstream s(str);
        vector<string> res;
        string ele;
        int i;
        for(i = 0; i < str.size() - 1; i++) {
            if(str[i+1] == ';') {
                ele.push_back(str[i]);
                res.push_back(ele);
                ele.clear();
                i++;
            } else {
                ele.push_back(str[i]);
            }
        }
        ele.push_back(str[i]);
        res.push_back(ele);
        return res;
    }
};

int main()
{
    vector<string> l {"lint",";",";","love","you"};
    Solution s;
    string res = s.encode(l);
    cout << res << endl;
    vector<string> res2 = s.decode(res);
    for(auto i : res2) {
        cout << i << endl;
    }
    return 0;
}