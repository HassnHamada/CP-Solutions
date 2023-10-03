#ifdef ONLINE_JUDGE
#include <bits/stdc++.h>
#endif
#include <stdio.h>
#include <algorithm>
#include <numeric>
using namespace std;
typedef long long ll;

const int N = 4e4 + 10;

int arr[N], idx[N], ans[N];

void run()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", arr + i);
    }
    iota(idx, idx + n, 0);
    sort(idx, idx + n, [](const int v1, const int v2)
         { return arr[v1] < arr[v2]; });
    for (int i = 0; i < n; i++)
    {
        ans[idx[i]] = n - i;
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d%c", ans[i], " \n"[i + 1 == n]);
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("_output.txt", "w", stdout);
    freopen("_input.txt", "r", stdin);
#endif
    int t = 1;
    scanf("%d", &t);
    while (t--)
    {
        run();
    }
    return 0;
}