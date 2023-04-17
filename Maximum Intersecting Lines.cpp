#include <bits/stdc++.h>
using namespace std;

int maxIntersections(vector<vector<int>> lines, int N)
{
    unordered_map<int, int> m;

    for (auto line : lines)
        m[line[0]]++, m[line[1] + 1]--;

    int maxIntersections = 0, prefixSum = 0;
    for (auto it : m)
    {
        prefixSum += it.second;
        maxIntersections = max(maxIntersections, prefixSum);
    }

    return maxIntersections;
}