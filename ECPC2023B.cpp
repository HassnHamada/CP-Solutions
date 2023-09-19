// #include <bits/stdc++.h>
#include <stdio.h>
#include <algorithm>
#include <assert.h>
#include <string.h>
using namespace std;
typedef long long ll;

const int N = 3e5 + 10, MOD = 1e9 + 7;

char str[N];

int frq[N];

void run()
{
    scanf("%s", str);
    int n = strlen(str);
    for (int i = 0, j = 0; i < n; frq[j]++, i++, j += str[i] != str[i - 1]);
    int m = unique(str, str + n) - str;
    ll ans = 1;
    for (int i = 0; i < m; i++)
    {
        assert(frq[i]);
        ans = ans * frq[i] % MOD;
    }
    printf("%d %lld\n", m, ans);
    memset(frq, 0, sizeof(frq[0]) * m);
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