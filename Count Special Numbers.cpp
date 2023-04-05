#include <bits/stdc++.h>
using namespace std;

int countSpecialNumbers(int N, vector<int> arr)
{
    int count = 0;
    unordered_map<int, int> mp;
    int maxx = INT_MIN;
    for (int i = 0; i < N; i++)
    {
        maxx = max(maxx, arr[i]);
        mp[arr[i]]++;
    }

    for (int i = 0; i < N; i++)
    {
        if (mp[arr[i]] > 1)
        {
            count++;
            continue;
        }

        for (int j = 1; j <= arr[i] / 2; j++)
        {
            if ((arr[i] % j == 0) && mp[j] >= 1)
            {
                count++;
                break;
            }
        }
    }
    return count;
}
