#include <bits/stdc++.h>
using namespace std;

// void slove(int i, int j, vector<vector<int>> &m, int n, string moves, vector<string> &ans, vector<vector<int>> &vis)
// {
//     if (i == n - 1 && j == n - 1)
//     {
//         ans.push_back(moves);
//         return;
//     }
//     // down
//     if (i + 1 < n && !vis[i + 1][j] && m[i + 1][j])
//     {
//         vis[i][j] = 1;
//         slove(i + 1, j, m, n, moves + "D", ans, vis);
//         vis[i][j] = 0;
//     }
//     // left
//     if (j - 1 >= 0 && !vis[i][j - 1] && m[i][j - 1])
//     {
//         vis[i][j] = 1;
//         slove(i, j - 1, m, n, moves + "L", ans, vis);
//         vis[i][j] = 0;
//     }
//     // right
//     if (j + 1 < n && !vis[i][j + 1] && m[i][j + 1])
//     {
//         vis[i][j] = 1;
//         slove(i, j + 1, m, n, moves + "R", ans, vis);
//         vis[i][j] = 0;
//     }
//     // up
//     if (i - 1 >= 0 && !vis[i - 1][j] && m[i - 1][j])
//     {
//         vis[i][j] = 1;
//         slove(i - 1, j, m, n, moves + "U", ans, vis);
//         vis[i][j] = 0;
//     }
// }

void slove(int i, int j, vector<vector<int>> &m, int n, string a, vector<string> &ans, vector<vector<int>> &vis)
{
    if (i < 0 || j < 0 || i >= n || j >= n || m[i][j] == 0 || vis[i][j] == 1)
        return;

    if (i == n - 1 && j == n - 1)
    {
        ans.push_back(a);
        return;
    }

    vis[i][j] = 1;

    slove(i + 1, j, m, n, a + 'D', ans, vis);
    slove(i, j - 1, m, n, a + 'L', ans, vis);
    slove(i, j + 1, m, n, a + 'R', ans, vis);
    slove(i - 1, j, m, n, a + 'U', ans, vis);

    vis[i][j] = 0;
}

vector<string> findPath(vector<vector<int>> &m, int n)
{
    vector<string> ans;
    vector<vector<int>> vis(n, vector<int>(n));
    string a = "";

    slove(0, 0, m, n, a, ans, vis);

    return ans;
}

int main()
{
    vector<vector<int>> m = {{1, 0, 0, 0},
                             {1, 1, 0, 1},
                             {1, 1, 0, 0},
                             {0, 1, 1, 1}};

    vector<string> res = findPath(m, 4);
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << " ";

    return 0;
}