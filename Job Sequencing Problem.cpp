#include <bits/stdc++.h>
using namespace std;

struct Job
{
    int id;
    int dead;
    int profit;
};

bool compare(Job a, Job b)
{
    return a.profit > b.profit;
}

vector<int> JobScheduling(Job arr[], int n)
{
    sort(arr, arr + n, compare);
    int maxDead = 0;
    for (int i = 0; i < n; i++)
        maxDead = max(maxDead, arr[i].dead);
    vector<int> ans(maxDead + 1, -1);
    int count = 0, profit = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = arr[i].dead; j > 0; j--)
        {
            if (ans[j] == -1)
            {
                ans[j] = arr[i].id;
                count++;
                profit += arr[i].profit;
                break;
            }
        }
    }
    return {count, profit};
}

vector<int> JobScheduling(Job arr[], int n)
{
    // your code here
}