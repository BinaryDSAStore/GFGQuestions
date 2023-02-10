#include <bits/stdc++.h>
using namespace std;

int maxInstance(string s)
{
    map<char, int> mp;

    for (int i = 0; i < s.size(); i++)
        if (s[i] == 'b' || s[i] == 'a' || s[i] == 'l' || s[i] == 'o' || s[i] == 'n')
            mp[s[i]]++;

    int ans = s.size();
    mp['l'] = mp['l'] / 2;
    mp['o'] = mp['o'] / 2;
    
    for (auto it : mp)
        ans = min(ans, it.second);

    return mp.size() == 5 ? ans : 0;
}