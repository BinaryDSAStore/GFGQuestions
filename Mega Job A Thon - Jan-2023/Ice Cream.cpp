#include <bits/stdc++.h>
using namespace std;

long long findGoodPairs(vector<int> a, int n, int k)
{
    long long ans = 0;
    unordered_map<int, vector<int>> m;

    for (int i = 0; i < n; i++)
        m[a[i]].push_back(i);

    for (auto i : m)
    {
        // element difference is atleat k
        for (int k{0}; k < i.second.size(); k++)
        {
            for (int j = k + 1; j < i.second.size(); j++)
            {
                if (i.second[j] - i.second[k] >= k)
                    ans++;
            }
        }
    }

    return ans;
}
