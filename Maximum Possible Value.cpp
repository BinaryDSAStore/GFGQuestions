#include <bits/stdc++.h>
using namespace std;
long long maxPossibleValue(int N, vector<int> A, vector<int> B)
{
    long long ans{0};
    long long noofsticks{0};
    int minlen{INT_MAX};

    for (int i = 0; i < N; i++)
    {
        int len = A[i];
        int unit = B[i];

        if (unit % 2)
            unit--;

        if (unit)
            minlen = min(len, minlen);

        ans += len * unit;
        noofsticks += unit;
    }

    if (noofsticks % 4)
        return ans - 2 * minlen;
    else
        return ans;
}