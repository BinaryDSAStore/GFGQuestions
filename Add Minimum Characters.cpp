#include <bits/stdc++.h>
using namespace std;

int addMinChar(string str)
{
    int n = str.length();
    int l = 0, r = n - 1;
    int le = n - 1;
    while (l <= r)
    {
        if (str[l] == str[r])
        {
            l++;
            r--;
        }
        else
        {
            l = 0;
            le--;
            r = le;
        }
    }
    return n - 1 - le;
}