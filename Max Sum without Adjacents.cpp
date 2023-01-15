#include <bits/stdc++.h>
using namespace std;

int findMaxSum(int *arr, int n)
{
    int a = 0;
    int b = arr[0];

    for (int i = 2; i <= n; i++)
    {
        int c = max(b, a + arr[i - 1]);
        a = b;
        b = c;
    }
    return b;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << findMaxSum(arr, n) << endl;
    return 0;
}