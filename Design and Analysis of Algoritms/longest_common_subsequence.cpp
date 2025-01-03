#include <iostream>
#include <vector>
#include <string>
using namespace std;

int recursive_lcs(string s1, string s2) {
    if (s1.empty() || s2.empty()) {
        return 0;
    }
    if(s1[s1.size() - 1] == s2[s2.size() - 1]) {
        s1.pop_back(), s2.pop_back();
        return 1 + recursive_lcs(s1, s2);
    } else {
        return max(recursive_lcs(s1.substr(0, s1.size() - 1), s2), recursive_lcs(s1,s2.substr(0, s2.size() - 1)));
    }
}

int dp_lcs(string s1, string s2, vector<vector <int>> &dp) {
    if(s1.empty() || s2.empty()) {
        return 0;
    }
    if(s1.back() == s2.back()) {
        return dp[s1.size()][s2.size()] = 1 + dp_lcs(s1.substr(0, s1.size()-1), s2.substr(0, s2.size() - 1), dp);
    }

    if(dp[s1.size()][s2.size()] != -1) return dp[s1.size()][s2.size()];
    else return dp[s1.size()][s2.size()] = max(dp_lcs(s1.substr(0, s1.size()-1), s2, dp), dp_lcs(s1, s2.substr(0, s2.size() - 1), dp));
}

int main() {
    string s1 = "AGGTAB";
    string s2 = "GXTXAYB";
    cout << recursive_lcs(s1, s2) << endl;

    vector<vector<int>> dp(s1.size() + 1, vector<int>(s2.size() + 1, -1));
    cout << dp_lcs(s1,s2,dp) << endl;
}