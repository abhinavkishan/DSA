// link: https://practice.geeksforgeeks.org/problems/max-triplet-sum/0

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    long long maxTripletProduct(long long arr[], int n)
    {
    	sort(arr, arr + n);
    	return max(arr[0] * arr[1] * arr[n - 1], arr[n - 1] * arr[n - 2] * arr[n - 3]);
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        long long a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        Solution ob;
        cout << ob.maxTripletProduct(a, n) << endl;
    }
    return 0;
}


