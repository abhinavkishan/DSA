#include <bits/stdc++.h>
using namespace std;

bool compare(pair<int, int>& a, pair<int, int>& b) {
    if(a.second < b.second) return true;
    if(a.second > b.second) return false;
    // if second element is same then sort according to first element
    if(a.first > b.first) {
        return true;
    } 
    return false;
} 

void sort_algo() {
    // sort(starting iterator, ending iterator) -> [start, end)
    // array<int, 5> arr = {5, 4, 3, 2, 1};
    array<int, 5> arr{5, 4, 3, 2, 1};
    sort(arr.begin() + 2, arr.end());
    for (auto i : arr) {
        cout << i << " ";
    }
    cout << endl;
    // sorting in descending order
    arr = {1, 2, 3, 4, 5};
    sort(arr.begin(), arr.end(), greater<int>());
    for (auto i : arr) {
        cout << i << " ";
    }
    cout << endl;
    // custom sorting
    // sort pair according to second element
    vector<pair<int, int>> v = {{1, 2}, {2, 1}, {4, 1}};
    sort(v.begin(), v.end(), [](pair<int, int> &a, pair<int, int> &b) {
        if(a.second == b.second) {
            return a.first > b.first;
        } else {
            return a.second < b.second;
        }
    });
    for (auto i : v) {
        cout << i.first << " " << i.second << endl;
    }
    cout << endl;
    // number of set bits
    cout << __builtin_popcount(7) << endl;
    // manupulating bits
    int n = 7;
    int count = 0;
    while(n > 0) {
        if(n & 1) {
            count++;
        }
        n = n >> 1;
    }
    cout << count << endl;
    long long int x = 1e18;
    cout << x << endl;
    cout << __builtin_popcountll(x) << endl;
    // num of permutations
    string s = "123";
    // start from sorted string to print all permutations
    cout << "Different permutations of string " << s << " are: " << endl;
    do {
        cout << s << endl;
    } while(next_permutation(s.begin(), s.end()));

    // max element
    vector<int> v1 = {1, 2, 3, 4, 5};
    cout << *max_element(v1.begin(), v1.end()) << endl;
}

int main()
{
    sort_algo();
    return 0;
}