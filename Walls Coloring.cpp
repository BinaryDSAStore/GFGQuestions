#include <bits/stdc++.h>
using namespace std;

// recursive
// int minCostrec(vector<vector<int>> &colors, int N, int idx, int prev)
// {
//     if (idx == N)
//         return 0;
//     int minres = 1e8;

//     for (int i{0}; i < 3; i++)
//     {
//         if (i == prev)
//             continue;

//         int temp = colors[idx][i] + minCostrec(colors, N, idx + 1, i);
//         minres = min(minres, temp);
//     }
//     return minres;
// }

// int minCost(vector<vector<int>> &colors, int N)
// {
//     return minCostrec(colors, N, 0, -1);
// }

// memoization
// int minCostMemo(vector<vector<int>> &colors, int N, int idx, int prev, vector<vector<int>> &dp)
// {
//     if (idx == N)
//         return 0;

//     if (dp[idx][prev + 1] != -1)
//         return dp[idx][prev + 1];

//     int minres = 1e8;

//     for (int i{0}; i < 3; i++)
//     {
//         if (i == prev)
//             continue;

//         int temp = colors[idx][i] + minCostMemo(colors, N, idx + 1, i, dp);
//         minres = min(minres, temp);
//     }
//     return dp[idx][prev + 1] = minres;
// }

// int minCost(vector<vector<int>> &colors, int N)
// {
//     vector<vector<int>> dp(N, vector<int>(4, -1));
//     return minCostMemo(colors, N, 0, -1, dp);
// }

// tabulation

int minCost(vector<vector<int>> &colors, int N)
{
    vector<vector<int>> dp(N + 1, vector<int>(4));

    for (int idx{N - 1}; idx >= 0; idx--)
    {
        int minres = 1e8;

        for (int i{0}; i < 3; i++)
        {

            int temp = colors[idx][i] + dp[idx + 1][i + 1];
            minres = min(minres, temp);
            dp[idx][i + 1] = minres;
        }
    }

    return dp[0][0];
}
