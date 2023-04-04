#include <bits/stdc++.h>
using namespace std;

int xmod11(string x)
{
    int oddsum = 0, evensum = 0;

    for (long long i = 0; i < x.size(); i++)
    {
        if (i % 2 == 0)
            oddsum += x[i] - '0';
        else
            evensum += x[i] - '0';

        if (oddsum > 11 && evensum > 11)
        {
            oddsum -= 11;
            evensum -= 11;
        }
    }

    int ans = abs(oddsum - evensum) % 11;

    if (evensum < oddsum)
        ans = 11 - ans;
    
    // return abs(oddsum - evensum) % 11;
    return ans % 11;
}