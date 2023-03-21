#include <bits/stdc++.h>
using namespace std;

// recursive
// long long sloverec(int N, int K, vector<long long> GeekNum)
// {
//     if (N < GeekNum.size())
//         return GeekNum[N];

//     long long sum = 0;
//     for (int i = 1; i <= K; i++)
//         sum += sloverec(N - i, K, GeekNum);

//     return sum;
// }

// long long solve(int N, int K, vector<long long> GeekNum)
// {
//     return sloverec(N - 1, K, GeekNum);
// }

// Memoization
// long long sloveMemo(int N, int K, vector<long long> GeekNum, vector<long long> &dp)
// {
//     if (N < GeekNum.size())
//         return GeekNum[N];

//     if (dp[N] != -1)
//         return dp[N];

//     long long sum = 0;
//     for (int i = 1; i <= K; i++)
//         sum += sloveMemo(N - i, K, GeekNum, dp);

//     return dp[N] = sum;
// }

// long long solve(int N, int K, vector<long long> GeekNum)
// {
//     vector<long long> dp(N + 1, -1);
//     return sloveMemo(N - 1, K, GeekNum, dp);
// }

// Tabulation
long long solve(int N, int K, vector<long long> GeekNum)
{
    vector<long long> dp(N + 1, 0);
    for (int i = 0; i < GeekNum.size(); i++)
        dp[i] = GeekNum[i];

    for (int i = GeekNum.size(); i <= N; i++)
    {
        long long sum = 0;
        for (int j = 1; j <= K; j++)
            sum += dp[i - j];

        dp[i] = sum;
    }

    return dp[N];
}
