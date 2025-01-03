#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

void table(string pat, int table[])
{
    int i, j, m = pat.length();
    for (i = 0; i < 256; i++)
        table[i] = m;
    for (j = 0; j < m - 1; j++)
        table[pat[j]] = m - 1 - j;
}

int horspool(string text, string pat)
{
    int i, j, k, m = pat.length(), n = text.length();
    int table_arr[256];
    table(pat, table_arr);
    i = m - 1;
    while (i < n)
    {
        k = 0;
        while ((k < m) && (pat[m - 1 - k] == text[i - k]))
            k++;
        if (k == m)
            return i - m + 1;
        else
            i += table_arr[text[i]];
    }
    return -1;
}

int main()
{
    string text, pat;
    cout << "Enter text: ";
    getline(cin, text);
    cout << "Enter pattern: ";
    getline(cin, pat);
    int pos = horspool(text, pat);
    if (pos == -1)
        cout << "Pattern not found" << endl;
    else
        cout << "Pattern found at position " << pos << endl;
    return 0;
}