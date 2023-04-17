#include <bits/stdc++.h>
using namespace std;

int dominantPairs(int n, vector<int> &arr)
{
    sort(arr.begin(), arr.begin() + (n / 2));
    sort(arr.begin() + (n / 2), arr.end());
    int left = (n / 2) - 1;
    int right = n - 1;

    int ans = 0;
    while (left >= 0 && right >= n / 2)
    {
        if (arr[left] >= 5 * arr[right])
        {
            ans += right - (n / 2) + 1;
            left--;
        }
        else
        {
            right--;
        }
    }
    return ans;
}