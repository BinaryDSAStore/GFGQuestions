#include <bits/stdc++.h>
using namespace std;

int minimumTime(int N, int cur, vector<int> &pos, vector<int> &time)
{
    int n = pos.size();
    int ans = INT_MAX;
    for (int i = 0; i < n; i++)
        ans = min(ans, abs(cur - pos[i]) * time[i]);

    return ans;
}