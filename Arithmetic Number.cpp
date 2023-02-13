#include <bits/stdc++.h>
using namespace std;

int inSequence(int A, int B, int C)
{
    if (!C)
        return A == B;

    int n{0};
    n = ((B - A) / C) + 1;

    if (n < 1)
        return 0;

    return A + ((n - 1) * C) == B;
}