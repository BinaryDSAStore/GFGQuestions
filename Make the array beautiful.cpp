#include <bits/stdc++.h>
using namespace std;

vector<int> makeBeautiful(vector<int> arr)
{
    vector<int> ans;
    stack<int> st;
    for (int i = 0; i < arr.size(); i++)
    {
        if (st.empty())
            st.push(arr[i]);

        else if (st.top() >= 0 && arr[i] >= 0 || st.top() < 0 && arr[i] < 0)
            st.push(arr[i]);
        else
            st.pop();
    }

    int n = st.size();
    for (int i = 0; i < n; i++)
    {
        if (!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}