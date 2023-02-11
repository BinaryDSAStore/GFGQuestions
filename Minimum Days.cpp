#include <bits/stdc++.h>
using namespace std;

int getMinimumDays(int N, string S, vector<int> &P)
{
    vector<int> ref(N);
    for (int i{0}; i < N; i++)
        ref[P[i]] = i;

    int ans = -1;

    for (int i{0}; i < N - 1; i++)
    {
        if (S[i] == S[i + 1])
        {
            int temp = min(ref[i], ref[i + 1]);
            ans = max(temp, ans);
        }
    }

    return ans+1;
}
