// #include <bits/stdc++.h>
#include <stdio.h>
#include <memory.h>
#include <iostream>
using namespace std;
typedef long long ll;

// const int N = 2e5 + 10, M = 2, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;
const int N = 2e5 + 10;

int arr[N], dp[N], prv[N];

void run()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", arr + i);
    }
    dp[n] = 0;
    memset(prv, -1, sizeof(prv[0]) * (n + 1));
    for (int i = n - 1; ~i; i--)
    {
        if (~prv[arr[i]])
        {
            dp[i] = max({dp[i + 1], prv[arr[i]] - i + dp[prv[arr[i]]],
                         prv[arr[i]] - i + 1 + dp[prv[arr[i]] + 1]});
        }
        else
        {
            dp[i] = dp[i + 1];
        }
        prv[arr[i]] = i;
    }
    printf("%d\n", dp[0]);
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