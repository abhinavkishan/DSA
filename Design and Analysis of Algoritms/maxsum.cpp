/* You are given three arrays containing positive numbers. Let
sum1 be the sum of elements present in array-1, sum2 be the sum of
elements present in array-2, sum3 be the sum of elements present in
array-3. The task is to make sum1=sum2=sum3 and it should be as
maximum as possible, if not possible return sum as 0. The only operation
allowed is the removal of elements from the beginning of array. */

#include <bits/stdc++.h>
using namespace std;

int arrsum(int a[], int s, int n)
{
    int sum = 0;
    for (int i = s; i < n; i++)
        sum += a[i];
    return sum;
}


int maxsum(int a[], int b[], int c[], int n1, int n2, int n3)
{
    int i = 0, j = 0, k = 0;
    int sum1 = 0, sum2 = 0, sum3 = 0;
    int result = 0;
    sum1 = arrsum(a, i, n1);
    sum2 = arrsum(b, j, n2);
    sum3 = arrsum(c, k, n3);

    while( i < n1 && j < n2 && k < n3) {
        if(sum1 == sum2 && sum2 == sum3) return sum1;
        if(sum1 >= sum2 && sum1 >= sum3) sum1 -= a[i++];
        else if(sum2 >= sum1 && sum2 >= sum3) sum2 -= b[j++];
        else if(sum3 >= sum1 && sum3 >= sum2) sum3 -= c[k++];
    }
    return 0;
}

int main()
{
    int n1, n2, n3;
    cin >> n1 >> n2 >> n3;
    int a[n1], b[n2], c[n3];
    for (int i = 0; i < n1; i++)
        cin >> a[i];
    for (int i = 0; i < n2; i++)
        cin >> b[i];
    for (int i = 0; i < n3; i++)
        cin >> c[i];

    cout << maxsum(a, b, c, n1, n2, n3) << endl;
        
    return 0;
}