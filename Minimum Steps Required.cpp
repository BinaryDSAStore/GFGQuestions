#include <bits/stdc++.h>
using namespace std;

int minSteps(string str)
{
    int n = str.size();
    if (!n)
        return 0;
    vector<int> blockcount;

    for (int i = 0; i < n; i++)
    {
        int count = 1;
        while (i < n - 1 && str[i] == str[i + 1])
        {
            count++;
            i++;
        }
        blockcount.push_back(count);
    }

    return ((blockcount.size() / 2) + 1);
}