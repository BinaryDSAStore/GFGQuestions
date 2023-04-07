#include <bits/stdc++.h>
using namespace std;

int equalSum(int N, vector<int> &A)
{
    long long sum = 0;
    sum = accumulate(A.begin(), A.end(), sum);
    long long leftSum = 0;
    for (int i = 0; i < N; i++)
    {
        sum -= A[i];
        if (leftSum == sum)
            return i + 1;
        leftSum += A[i];
    }
    return -1;
}