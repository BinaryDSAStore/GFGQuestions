#include <bits/stdc++.h>
using namespace std;

vector<long long int> countZero(int n, int k, vector<vector<int>> &arr)
{
    vector<long long int> ans;
    int rk = 0, ck = 0;
    long long temp = n * n;

    vector<bool> row(n + 1), col(n + 1);

    for (int i = 0; i < k; i++)
    {
        int r = arr[i][0], c = arr[i][1];
        if (row[r] && col[c])
        {
        }
        else if (row[r])
        {
            col[c] = true;
            ck++;
            temp = temp - n + rk;
        }
        else if (col[c])
        {
            row[r] = true;
            rk++;
            temp = temp - n + ck;
        }
        else
        {
            row[r] = true;
            col[c] = true;
            temp = temp - n + ck - n + rk + 1;
            ck++;
            rk++;
        }
        ans.push_back(temp);
    }
    return ans;
}