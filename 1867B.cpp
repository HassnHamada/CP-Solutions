#ifdef ONLINE_JUDGE
#include <bits/stdc++.h>
#endif
#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;
typedef long long ll;

const int N = 1e5 + 10;
char str[N], ans[N];

void run()
{
    int n, c = 0;
    scanf("%d\n%s", &n, str);
    for (int i = 0; i < n / 2; i++)
    {
        c += str[i] ^ str[n - i - 1];
    }
    fill(ans, ans + n + 1, '0');
    for (int i = c; i <= n - c; i += 2)
    {
        ans[i] = '1';
        if (n & 1)
        {
            ans[i + 1] = '1';
        }
    }
    ans[n + 1] = '\0';
    printf("%s\n", ans);
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