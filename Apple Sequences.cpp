#include <bits/stdc++.h>
using namespace std;

int appleSequences(int n, int m, string arr)
{
    int cnt0 = 0;
    int l = 0;
    int max_len = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 'O')
            cnt0++;

        while (cnt0 > m)
        {
            if (arr[l] == 'O')
                cnt0--;
            l++;
        }

        max_len = max(max_len, i - l + 1);
    }

    return max_len;
}