#include <bits/stdc++.h>
using namespace std;

// recursive
int countWaystoDividerec(int n, int k, int prev)
{
    if (n == 0 && k == 0)
        return 1;

    if (n <= 0 || k <= 0)
        return 0;

    int sum = 0;

    for (int i = prev; i <= n; i++)
        sum += countWaystoDividerec(n - i, k - 1, i);

    return sum;
}

int countWaystoDivide(int n, int k)
{
    return countWaystoDividerec(n, k, 1);
}

// Memoization
int countWaystoDividememo(int n, int k, int prev, vector<vector<vector<int>>> &dp)
{
    if (n == 0 && k == 0)
        return 1;

    if (n <= 0 || k <= 0)
        return 0;

    if (dp[n][k][prev] != -1)
        return dp[n][k][prev];

    int sum = 0;

    for (int i = prev; i <= n; i++)
        sum += countWaystoDividememo(n - i, k - 1, i, dp);

    return dp[n][k][prev] = sum;
}

int countWaystoDivide(int n, int k)
{
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(k + 1, vector<int>(n + 1, -1)));
    return countWaystoDividememo(n, k, 1, dp);
}

// Tabulation
// int countWaystoDivide(int n, int k)
// {
//     vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(k + 1, vector<int>(n + 1, 0)));

//     for (int i = 1; i <= n; i++)
//         dp[0][0][i] = 1;

//     for (int i = 1; i <= n; i++)
//     {
//         for (int j = 1; j <= k; j++)
//         {
//             for (int l = 1; l <= n; l++)
//             {
//                 int sum = 0;
//                 for (int m = l; m <= n; m++)
//                     sum += dp[i - m][j - 1][l];
//                 dp[i][j][l] = sum;
//             }
//         }
//     }

//     return dp[n][k][1];
// }