#include <bits/stdc++.h>
using namespace std;

// find longest subarray of 1's by toggling a subarray of 0's
// https://www.geeksforgeeks.org/find-longest-subarray-of-1s-by-toggling-a-subarray-of-0s/

int toggle(int n, vector<int> &arr)
{
    vector<string> blocks;
    string block = "";

    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            block += to_string(arr[i]);
        }
        else
        {
            if (arr[i] == arr[i - 1])
            {
                block += to_string(arr[i]);
            }
            else
            {
                blocks.push_back(block);
                block = "";
                block += to_string(arr[i]);
            }
        }
    }
    blocks.push_back(block);

    if (blocks.size() == 1)
        return blocks[0].length();
    if (blocks.size() == 2)
        return blocks[0].length() + blocks[1].length();

    int ans = 0;
    for (int i = 0; i < blocks.size(); i++)
    {
        if (blocks[i][0] == '0')
        {
            if (i > 0)
            {
                int temo = blocks[i - 1].length() + blocks[i].length();
                if (i + 1 < blocks.size())
                    temo += blocks[i + 1].length();
                ans = max(ans, temo);
                cout << ans << endl;
            }
            else
            {
                int temo = blocks[i].length();
                if (i + 1 < blocks.size())
                    temo += blocks[i + 1].length();
                ans = max(ans, temo);
                cout << ans << endl;
            }
        }
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << toggle(n, arr) << endl;
    return 0;
}